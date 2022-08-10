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
    SURFACEINFO g_sfBack;			// 버퍼 표면
    SURFACEINFO g_sfBG;				// 배경 표면 

protected:

};