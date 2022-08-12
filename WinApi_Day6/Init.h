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
    void SetAniInt(int n);
	void MoveBg(HWND hWnd, int nLeftFlag);
	void MoveChar(HDC dcScreen, int nChrX, int nChrY, BOOL bMirror);
	void ImgOutComplete(HWND hWnd, HDC dcScreen);
    void DestroyAll();
	void SetCharPos(int nX, int nY);

private:
    char strName[24];
    SURFACEINFO g_sfBack;			// 버퍼 표면
    SURFACEINFO g_sfBG;				// 배경 표면
    Monster g_objCar[2];
    Image img;
    BOOL bRval;
	BOOL bChrMirror = FALSE;
    int g_nFrame = 0;					// 화면 갱신 카운트

	int x = 1380 / 2;
	int y = 600;
protected:

};