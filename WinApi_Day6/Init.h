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
    SURFACEINFO g_sfBack;			// 버퍼 표면
    SURFACEINFO g_sfBG;				// 배경 표면
    Monster g_objCar[2];
    Image img;
    BOOL  bRval;
    int g_nFrame = 0;					// 화면 갱신 카운트
protected:

};