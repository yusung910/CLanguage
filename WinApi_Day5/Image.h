#pragma once
#include "resource.h"
#include <windows.h>
class Image {

public:
	Image();
	Image(HWND hWnd, HINSTANCE g_hInst);

	~Image();

	void PutImage();
	void PutImageBlend(int nAlpha);
	void PutSprite(COLORREF colorkey);
	void DeleteImage();
protected:
	HDC hdc;
	PAINTSTRUCT ps;
	HDC MemDC;

	HBITMAP MyBitmap, OldBitmap;
	BITMAP bit;
	BLENDFUNCTION bf;

	HWND imgHwnd;

	int bx, by;
private:
};
