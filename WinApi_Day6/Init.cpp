#include "Init.h"
Init::Init() {
    //생성자
};

Init::~Init() {
    //소멸자
}

void Init::Begin(HDC dcScreen) {
	//생성자
	int i;
    ////
    g_objCar[0].nAni = 0;
    g_objCar[1].nAni = 1;
	////
	g_sfBack.CreateBackBuffer(dcScreen, 1380, 862, 32);

	////
	//g_sfBG-> = __MakeDDBFromDIB(dcScreen, "map.bmp");
	g_sfBG.SetHBmp(MakeDDBFromDIB(dcScreen, "m1.bmp"));
	g_sfBG.LoadSurface(dcScreen);

    nCharX = g_sfBG.GetWidth() / 2;
    nCharY = 600;
	//
	for (i = 0; i < 6; i++)
	{
        g_objCar[0].g_sfCar[i].SetCrColorKey(RGB(147, 187, 236));
	    g_objCar[1].g_sfCar[i].SetCrColorKey(RGB(147, 187, 236));
        
	    wsprintf(strName, "sonic%d.bmp", i);

	    g_objCar[0].g_sfCar[i].SetHBmp(MakeDDBFromDIB(dcScreen, strName));
	    g_objCar[1].g_sfCar[i].SetHBmp(MakeDDBFromDIB(dcScreen, strName));

        g_objCar[0].g_sfCar[i].LoadSurface(dcScreen);
        g_objCar[1].g_sfCar[i].LoadSurface(dcScreen);
	}
};

void Init::DestroyAll() {
    for (int i = 0; i < 6; i++) {
        g_objCar[0].g_sfCar[i].ReleaseSurface();
        g_objCar[1].g_sfCar[i].ReleaseSurface();
    }
    g_sfBack.ReleaseSurface();
    g_sfBG.ReleaseSurface();
};

void Init::SetAniInt() {
    //// 애니메이션 인덱스
    g_objCar[0].nAni++;
    g_objCar[1].nAni++;
    if (g_objCar[0].nAni >= 5) g_objCar[0].nAni = 1;
    if (g_objCar[1].nAni >= 5) g_objCar[1].nAni = 1;
};
void Init::SetAniInt(int n) {
    g_objCar[0].nAni = n;
    g_objCar[1].nAni = n;
}
void Init::SetBgPos(int nX, int nY) {
	nBgX = nBgX + nX;
	nBgY = nBgY + nY;
}
void Init::MoveBg(HWND hWnd) {
	HDC dcScreen;
    SURFACEINFO* gSfBg = &g_sfBG;
	char strBuff[24];
    int nBgWidth = gSfBg->GetWidth();
	//// 출력부
	dcScreen = GetDC(hWnd);

    int nNextBgX = nBgX + nBgWidth;

    if (nNextBgX < 0) nBgX = 0;

    if (nBgX > 0) nNextBgX = nBgX - nBgWidth;

    if (nBgX == nBgWidth) nBgX = 0;



    TRACE2("nNextBgX : %d, nBgX : %d\n", nNextBgX, nBgX);
	//// 연산부
	//if (abs(n_bgX) == (1380 / 2) || abs(n_bgX) == 0) x = (1380 / 2) - x;
	//// 배경
	//-1380 , 0, 1380
	img.PutImage(g_sfBack.GetDcSurface(), nBgX, nBgY, gSfBg);
    
	img.PutImage(g_sfBack.GetDcSurface(), nNextBgX, 0, &g_sfBG);

	//__PutImageBlend(g_sfBack.dcSurface, 0, 0, &g_sfBG, 128);
	////				
	::wsprintf(strBuff, "Frame %d", ++g_nFrame);
	::TextOut(g_sfBack.GetDcSurface(), 10, 10, strBuff, strlen(strBuff));

	MoveChar(dcScreen, nCharX, nCharY, bChrMirror);

	ImgOutComplete(hWnd, dcScreen);
}

void Init::MoveChar(HDC dcScreen, int nChrX, int nChrY, BOOL bMirror) {
	//// 오브젝트 및 기타 인터페이스창
	bRval = img.PutSprite(g_sfBack.GetDcSurface(), nChrX, nChrY, &(g_objCar[0].g_sfCar[g_objCar[0].nAni]));
	if (!bRval)	::OutputDebugString("__PutSprite - fail");
}



void Init::ImgOutComplete(HWND hWnd, HDC dcScreen) {
	//// 출력 완료
	img.CompleteBlt(dcScreen, g_sfBack, &g_sfBack);

	ReleaseDC(hWnd, dcScreen);
}


SURFACEINFO Init::GetSfBack() {
	return g_sfBack;
};
SURFACEINFO Init::GetSfBg() {
	return g_sfBG;
};

void Init::SetCharPosY(int n) {
    nCharY = n;
};
int Init::GetCharPosY() {
    return nCharY;
};
