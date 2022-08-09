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