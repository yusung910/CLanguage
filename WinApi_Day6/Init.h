#pragma once
#include "windows.h"
#include "SURFACEINFO.h"
#include "ConvertBitMap.h"

class Init : public ConvertBitMap {
public:
    Init();
    Init(HDC dcScreen);

    ~Init();
private:
    char strName[24];
    SURFACEINFO g_sfBack;			// ���� ǥ��
    SURFACEINFO g_sfBG;				// ��� ǥ�� 

protected:

};