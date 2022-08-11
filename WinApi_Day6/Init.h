#pragma once
#include "windows.h"
#include "SURFACEINFO.h"
#include "ConvertBitMap.h"
#include "Monster.h"
#include "Image.h"
class Init : public ConvertBitMap {
public:
    Init();
    ~Init();
	void Begin(HDC dcScreen);
	SURFACEINFO GetSfBack();
	SURFACEINFO GetSfBg();

    void SetAniInt();
    void SetBackground(HDC dcScreen, int nBgX, int nChrX, int nChrY);
	void MoveChar(HDC dcScreen, int nChrX, int nChrY, BOOL bMirror);
	void ImgOutComplete(HWND hWnd, HDC dcScreen);
    void DestroyAll();


private:
    char strName[24];
    SURFACEINFO g_sfBack;			// ���� ǥ��
    SURFACEINFO g_sfBG;				// ��� ǥ��
    Monster g_objCar[2];
    Image img;
    BOOL  bRval;
    int g_nFrame = 0;					// ȭ�� ���� ī��Ʈ
protected:

};