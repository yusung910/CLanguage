#include "Image.h"
Image::Image() {
	//������
}
Image::Image(HWND hWnd, HINSTANCE g_hInst) {
	//������

	imgHwnd = hWnd;

	hdc = BeginPaint(imgHwnd, &ps);

	//// �޸� DC����
	//// ���� ������ ���� DC������ ��Ʈ���� ������ �� �ִ�
	//// ���ϰ� : HDC
	MemDC = CreateCompatibleDC(hdc);

	//������
	MyBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));

	//// �޸�DC�� ��Ʈ�ʼ���
	//// ��Ʈ���� ���̿� ��, ���� ������ ������ �׸��� ǥ�� ����
	OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

	//// ������Ʈ�� ���� ������ ��ȸ
	GetObject(MyBitmap,		  // ������Ʈ �ڵ�
		sizeof(BITMAP), // ��Ʈ����ũ��
		&bit);		  // ��Ʈ���� ��, ����, ���� ���� ��Ʈ���� ( �ڵ�Ÿ�Կ� ���� �ٸ��� )
	bx = bit.bmWidth;
	by = bit.bmHeight;
}

Image::~Image() {
	//�Ҹ���
	
}
void Image::PutImage() {

    BitBlt(hdc,       // ����DC
        0, 0, bx, by, // ���� ��ǥ�� ��, ���� ( ��� )
		MemDC,				// �ҽ�DC
        0, 0,		  // �ҽ� ��ǥ ( copy ) , ���� ���� ���� ����
        SRCCOPY);  // ����
}

void Image::PutImageBlend(int nAlpha) {
	//// BLENDFUNCTION �ʱ�ȭ
	bf.BlendOp = AC_SRC_OVER;	//
	bf.BlendFlags = 0;				//			
	bf.AlphaFormat = 0;				//
	bf.SourceConstantAlpha = nAlpha; // ���� 0 - 255 ������

	//// ���� ����
	AlphaBlend(hdc,			// ����DC
		0, 0, bx, by,	// ������ǥ, ��, ����
		MemDC,		// �ҽ�DC
		0, 0, bx, by,	// 
		bf);			// BLENDFUNCTION ��Ʈ���� ( alpha-blending )
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

	//// ��Ʈ�� ����
	DeleteObject(MyBitmap);

	//// �޸� DC����
	DeleteDC(MemDC);

	EndPaint(imgHwnd, &ps);
}