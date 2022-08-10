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
    HDC			dcSurface;		// ��Ʈ���� ������ִ� ǥ�� DC
    HBITMAP		hBmp;			// ��Ʈ�� �ڵ�
    HBITMAP		hOldBmp;		// ���� ��Ʈ�� �ڵ� ( dc ������ ���� )
    int			nWidth;
    int			nHeight;
    COLORREF	crColorKey;		// �÷�Ű
private:
};