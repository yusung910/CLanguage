#pragma once
#include <windows.h>

class SURFACEINFO {
public:
    SURFACEINFO();
    ~SURFACEINFO();
    void CreateBackBuffer(HDC dcScreen, int nW, int nH, int nBPP);
    void LoadSurface(HDC dcScreen);
    void SetHBmp(HBITMAP bmp);
	void ReleaseSurface(SURFACEINFO* psInfo);
	int GetWidth();
	int GetHeight();
	HDC GetDcSurface();
	COLORREF GetCrColorKey();
protected:
    HDC			dcSurface;		// 비트맵이 적재되있는 표면 DC
    HBITMAP		hBmp;			// 비트맵 핸들
    HBITMAP		hOldBmp;		// 이전 비트맵 핸들 ( dc 해제시 참조 )
    int			nWidth;
    int			nHeight;
    COLORREF	crColorKey;		// 컬러키
private:
};