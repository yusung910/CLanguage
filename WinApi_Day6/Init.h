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
    SURFACEINFO g_sfBack;			// 버퍼 표면
    SURFACEINFO g_sfBG;				// 배경 표면
    Monster g_objCar[2];
    Image img;
    BOOL bRval;
	BOOL bChrMirror = FALSE;
    int g_nFrame = 0;					// 화면 갱신 카운트

	int nBgX = 0;
	int nBgY = 0;

    int nCharX = 0;
    int nCharY = 0;
protected:

};