#pragma once
#include <windows.h>
class ConvertBitMap {
public:
    ConvertBitMap();
    ~ConvertBitMap();
    HBITMAP MakeDDBFromDIB(HDC hdc, char *Path);
protected:
private:
};