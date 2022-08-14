#pragma once
#include "windows.h"
#include "SURFACEINFO.h"
#include "ConvertBitMap.h"
#include "Monster.h"
#include "Image.h"
#include "__debug.h"

class Init : public ConvertBitMap {
public:
    Init();
    ~Init();
	void Begin(HDC dcScreen);
	SURFACEINFO GetSfBack();
	SURFACEINFO GetSfBg();

    void SetAniInt();
    void SetAniInt(int n);
	void MoveBg(HWND hWnd);
	void MoveChar(HDC dcScreen, int nChrX, int nChrY, BOOL bMirror);
	void ImgOutComplete(HWND hWnd, HDC dcScreen);
    void DestroyAll();
	void SetBgPos(int nX, int nY);
    void SetCharPosY(int n);
    int GetCharPosY();

private:
    char strName[24];
    SURFACEINFO g_sfBack;			// ���� ǥ��
    SURFACEINFO g_sfBG;				// ��� ǥ��
    Monster g_objCar[2];
    Image img;
    BOOL bRval;
	BOOL bChrMirror = FALSE;
    int g_nFrame = 0;					// ȭ�� ���� ī��Ʈ

	int nBgX = 0;
	int nBgY = 0;

    int nCharX = 0;
    int nCharY = 0;
protected:

};