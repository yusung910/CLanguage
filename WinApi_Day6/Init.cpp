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
        
	    wsprintf(strName, "sonic%d.bmp", i + 1);

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
    if (g_objCar[0].nAni >= 5) g_objCar[0].nAni = 0;
    if (g_objCar[1].nAni >= 5) g_objCar[1].nAni = 0;
};

void Init::SetBackground(HWND hWnd, int nBgX) {
    char  strBuff[24];
    HDC dcScreen;
    //// ��º�
    dcScreen = GetDC(hWnd);

    //// ���
    img.PutImage(g_sfBack.GetDcSurface(), nBgX, 0, &g_sfBG);
    img.PutImage(g_sfBack.GetDcSurface(), nBgX + 1380, 0, &g_sfBG);

    //__PutImageBlend(g_sfBack.dcSurface, 0, 0, &g_sfBG, 128);

    //// ������Ʈ �� ��Ÿ �������̽�â
    bRval = img.PutSprite(g_sfBack.GetDcSurface(), 100, 100, &(g_objCar[0].g_sfCar[g_objCar[0].nAni]));
    if (!bRval)	::OutputDebugString("__PutSprite - fail");

    ////				
    ::wsprintf(strBuff, "Frame %d", ++g_nFrame);
    ::TextOut(g_sfBack.GetDcSurface(), 10, 10, strBuff, strlen(strBuff));

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

