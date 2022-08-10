#include "SURFACEINFO.h"
SURFACEINFO::SURFACEINFO() {

}

SURFACEINFO::~SURFACEINFO() {

}

void SURFACEINFO::CreateBackBuffer(HDC dcScreen, int nW, int nH, int nBPP) {
    dcSurface = CreateCompatibleDC(dcScreen);
    hBmp = CreateCompatibleBitmap(dcScreen, nW, nH);
    hOldBmp = (HBITMAP)SelectObject(dcSurface, hBmp);
    PatBlt(dcSurface, 0, 0, nW, nH, PATCOPY);
    nWidth = nW;
    nHeight = nH;
}

void SURFACEINFO::SetHBmp(HBITMAP bmp) {
    hBmp = bmp;
}


void SURFACEINFO::LoadSurface(HDC dcScreen) {
    BITMAP  bit;

    dcSurface = CreateCompatibleDC(dcScreen);
    hOldBmp = (HBITMAP)SelectObject(dcSurface, hBmp);

    GetObject(hBmp, sizeof(BITMAP), &bit);
    nWidth = bit.bmWidth;
    nHeight = bit.bmHeight;
}
//// 积己等 钎搁 秦力
void SURFACEINFO::ReleaseSurface(SURFACEINFO* psInfo)
{
	SelectObject(psInfo->dcSurface, psInfo->hOldBmp);
	DeleteDC(psInfo->dcSurface);
	DeleteObject(psInfo->hBmp);
}

int SURFACEINFO::GetWidth() {
	return nWidth;
};
int SURFACEINFO::GetHeight() {
	return nHeight;
};

HDC SURFACEINFO::GetDcSurface(){
	return dcSurface;
}
COLORREF SURFACEINFO::GetCrColorKey() {
	return crColorKey;
};