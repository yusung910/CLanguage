#include "Image.h"
Image::Image() {
	//생성자
}
Image::Image(HWND hWnd, HINSTANCE g_hInst) {
	//생성자

	imgHwnd = hWnd;

	hdc = BeginPaint(imgHwnd, &ps);

	//// 메모리 DC생성
	//// 색상 포맷이 같은 DC끼리는 비트맵을 전송할 수 있다
	//// 리턴값 : HDC
	MemDC = CreateCompatibleDC(hdc);

	//생성자
	MyBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));

	//// 메모리DC에 비트맵선택
	//// 비트맵의 높이와 폭, 색상 포맷을 가지는 그리기 표면 생성
	OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

	//// 오브젝트에 대한 정보를 조회
	GetObject(MyBitmap,		  // 오브젝트 핸들
		sizeof(BITMAP), // 스트럭쳐크기
		&bit);		  // 비트맵의 폭, 높이, 색상 정보 스트럭쳐 ( 핸들타입에 따라 다르다 )
	bx = bit.bmWidth;
	by = bit.bmHeight;
}

Image::~Image() {
	//소멸자
	
}
void Image::PutImage() {

    BitBlt(hdc,       // 목적DC
        0, 0, bx, by, // 목적 좌표와 폭, 높이 ( 출력 )
		MemDC,				// 소스DC
        0, 0,		  // 소스 좌표 ( copy ) , 목적 폭과 높이 참조
        SRCCOPY);  // 복사
}

void Image::PutImageBlend(int nAlpha) {
	//// BLENDFUNCTION 초기화
	bf.BlendOp = AC_SRC_OVER;	//
	bf.BlendFlags = 0;				//			
	bf.AlphaFormat = 0;				//
	bf.SourceConstantAlpha = nAlpha; // 투명 0 - 255 불투명

	//// 알파 블렌드
	AlphaBlend(hdc,			// 목적DC
		0, 0, bx, by,	// 목적좌표, 폭, 높이
		MemDC,		// 소스DC
		0, 0, bx, by,	// 
		bf);			// BLENDFUNCTION 스트럭쳐 ( alpha-blending )
}

void Image::PutSprite(COLORREF colorkey) {
	TransparentBlt(hdc,
	    0, 0, bx, by,
	    MemDC,
	    0, 0, bx, by,
		colorkey); // color key
}

void Image::DeleteImage() {
	SelectObject(MemDC, OldBitmap);

	//// 비트맵 해제
	DeleteObject(MyBitmap);

	//// 메모리 DC해제
	DeleteDC(MemDC);

	EndPaint(imgHwnd, &ps);
}