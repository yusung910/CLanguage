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

    //// ������ ����
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

    //// DDB�� ��ȯ�Ѵ�.
    hBit = CreateDIBitmap(hdc,						// hdc
        iheader,					// BITMAPINFOHEADER ���
        CBM_INIT,					// 0 �Ǵ� CBM_INIT ( �ʱ�ȭ )
        lpMemBlock + fh->bfOffBits,	// ������ ��巡��
        ih,							// BITMAPINFO ���
        DIB_RGB_COLORS);

    free(lpMemBlock);

    return hBit;
};