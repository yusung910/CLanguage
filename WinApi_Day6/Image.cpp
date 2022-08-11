#include "Image.h"

Image::Image() {

}

Image::~Image() {

}

//// �̹��� ���
BOOL Image::PutImage(HDC dcDst, int x, int y, SURFACEINFO* psInfo)
{
	return BitBlt(dcDst, x, y, psInfo->GetWidth(), psInfo->GetHeight(), psInfo->GetDcSurface(), 0, 0, SRCCOPY);
}

//// �̹��� ���� 
BOOL Image::PutImageBlend(HDC dcDst, int x, int y, SURFACEINFO* psInfo, int nAlpha)
{
	BLENDFUNCTION bf;

	//// BLENDFUNCTION �ʱ�ȭ
	bf.BlendOp = AC_SRC_OVER;	//
	bf.BlendFlags = 0;				//			
	bf.AlphaFormat = 0;				//
	bf.SourceConstantAlpha = nAlpha; // 0 - 255

	//// ���� ����
	return 	AlphaBlend(dcDst,
		x, y, psInfo->GetWidth(), psInfo->GetHeight(),
		psInfo->GetDcSurface(),
		0, 0, psInfo->GetWidth(), psInfo->GetHeight(),
		bf);
}

//// ��������Ʈ
BOOL Image::PutSprite(HDC dcDst, int x, int y, SURFACEINFO* psInfo)
{
	return TransparentBlt(dcDst,
		x, y, psInfo->GetWidth(), psInfo->GetHeight(),
		psInfo->GetDcSurface(),
		0, 0, psInfo->GetWidth(), psInfo->GetHeight(),
		psInfo->GetCrColorKey());
}

BOOL Image::PutMirror(HDC dcDst, int x, int y, SURFACEINFO* psInfo) {
	TransparentBlt(dcDst,
		x, y, psInfo->GetWidth(), psInfo->GetHeight(),
		psInfo->GetDcSurface(),
		0, 0, psInfo->GetWidth(), psInfo->GetHeight(),
		psInfo->GetCrColorKey());

	return 	StretchBlt(dcDst,
		x, y, -(psInfo->GetWidth()), psInfo->GetHeight(),
		psInfo->GetDcSurface(), 0, 0, psInfo->GetWidth(), psInfo->GetHeight(), SRCCOPY);
}

//// dcScreen�� ǥ���� ���� ( �ĸ�ǥ�� -> ȭ��DC )
BOOL Image::CompleteBlt(HDC dcScreen, SURFACEINFO g_sfBack, SURFACEINFO* psInfo)
{
	BitBlt(dcScreen, 0, 0, g_sfBack.GetWidth(), g_sfBack.GetHeight(), psInfo->GetDcSurface(), 0, 0, SRCCOPY);
	return TRUE;
}


void Image::ReleaseSurface(SURFACEINFO* psInfo){
    SelectObject(psInfo->GetDcSurface(), psInfo->GetOldBmpH());
    DeleteDC(psInfo->GetDcSurface());
    DeleteObject(psInfo->GetBmpH());
}