#include "ConvertBitMap.h"
ConvertBitMap::ConvertBitMap() {

};
ConvertBitMap::~ConvertBitMap() {

};

HBITMAP ConvertBitMap::MakeDDBFromDIB(HDC hdc, char *Path) {
    HANDLE  hFile;
    DWORD   FileSize, dwRead;
    HBITMAP hBit;
    BITMAPFILEHEADER *fh;
    BITMAPINFO		 *ih;
    BITMAPINFOHEADER *iheader;
    LPBYTE			 lpMemBlock;

    //// 파일을 연다
    hFile = CreateFile(Path, GENERIC_READ, 0, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        return NULL;
    }

    FileSize = GetFileSize(hFile, NULL);

    lpMemBlock = (LPBYTE)malloc(FileSize);
    fh = (BITMAPFILEHEADER *)lpMemBlock;
    ReadFile(hFile, lpMemBlock, FileSize, &dwRead, NULL);
    CloseHandle(hFile);

    ih = (BITMAPINFO*)(lpMemBlock + sizeof(BITMAPFILEHEADER));
    iheader = (BITMAPINFOHEADER*)(lpMemBlock + sizeof(BITMAPFILEHEADER));

    //// DDB로 변환한다.
    hBit = CreateDIBitmap(hdc,						// hdc
        iheader,					// BITMAPINFOHEADER 헤더
        CBM_INIT,					// 0 또는 CBM_INIT ( 초기화 )
        lpMemBlock + fh->bfOffBits,	// 래스터 어드래스
        ih,							// BITMAPINFO 헤더
        DIB_RGB_COLORS);

    free(lpMemBlock);

    return hBit;
};