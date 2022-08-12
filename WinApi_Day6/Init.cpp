#include "Init.h"
Init::Init() {
    //������
};

Init::~Init() {
    //�Ҹ���
}

void Init::Begin(HDC dcScreen) {
	//������
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
    //// �ִϸ��̼� �ε���
    g_objCar[0].nAni++;
    g_objCar[1].nAni++;
    if (g_objCar[0].nAni >= 5) g_objCar[0].nAni = 1;
    if (g_objCar[1].nAni >= 5) g_objCar[1].nAni = 1;
};
void Init::SetAniInt(int n) {
    g_objCar[0].nAni = n;
    g_objCar[1].nAni = n;
}
void Init::SetCharPos(int nX, int nY) {
	x = x + nX;
	y = y + nY;
}
void Init::MoveBg(HWND hWnd, int nLeftFlag) {
	HDC dcScreen;
	char strBuff[24];
	
	//// ��º�
	dcScreen = GetDC(hWnd);

	//// �����
	int n_bgX = (1380 / 2) - x;
	//if (abs(n_bgX) == (1380 / 2) || abs(n_bgX) == 0) x = (1380 / 2) - x;
	//// ���
	//-1380 , 0, 1380
	img.PutImage(g_sfBack.GetDcSurface(), n_bgX, 0, &g_sfBG);
	//img.PutImage(g_sfBack.GetDcSurface(), n_bgX + 1380, 0, &g_sfBG);

	//__PutImageBlend(g_sfBack.dcSurface, 0, 0, &g_sfBG, 128);
	////				
	::wsprintf(strBuff, "Frame %d", ++g_nFrame);
	::TextOut(g_sfBack.GetDcSurface(), 10, 10, strBuff, strlen(strBuff));

	MoveChar(dcScreen, (1380 / 2), y, bChrMirror);

	ImgOutComplete(hWnd, dcScreen);
}

void Init::MoveChar(HDC dcScreen, int nChrX, int nChrY, BOOL bMirror) {
	//// ������Ʈ �� ��Ÿ �������̽�â
	bRval = img.PutSprite(g_sfBack.GetDcSurface(), nChrX, nChrY, &(g_objCar[0].g_sfCar[g_objCar[0].nAni]));
	if (!bRval)	::OutputDebugString("__PutSprite - fail");
}



void Init::ImgOutComplete(HWND hWnd, HDC dcScreen) {
	//// ��� �Ϸ�
	img.CompleteBlt(dcScreen, g_sfBack, &g_sfBack);

	ReleaseDC(hWnd, dcScreen);
}


SURFACEINFO Init::GetSfBack() {
	return g_sfBack;
};
SURFACEINFO Init::GetSfBg() {
	return g_sfBG;
};

