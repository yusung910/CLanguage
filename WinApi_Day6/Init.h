#pragma once
#include "windows.h"
#include "SURFACEINFO.h"
#include "ConvertBitMap.h"

class Init : public ConvertBitMap {
public:
    Init();
    ~Init();
	void Begin(HDC dcScreen);
	SURFACEINFO GetSfBack();
	SURFACEINFO GetSfBg();
private:
    char strName[24];
    SURFACEINFO g_sfBack;			// ���� ǥ��
    SURFACEINFO g_sfBG;				// ��� ǥ�� 

protected:

};