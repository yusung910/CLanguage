#pragma once
#include <windows.h>
#include "SURFACEINFO.h"
class Image {
public:
	Image();
	~Image();

	BOOL PutImage(HDC dcDst, int x, int y, SURFACEINFO* psInfo);
	BOOL PutImageBlend(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int nAlpha);
	BOOL PutSprite(HDC dcDst, int x, int y, SURFACEINFO* psInfo);
	BOOL CompleteBlt(HDC dcScreen, SURFACEINFO g_sfBack, SURFACEINFO* psInfo);
    void Image::ReleaseSurface(SURFACEINFO* psInfo);
protected:
private:
};