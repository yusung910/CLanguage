#include "Init.h"

Init::Init() {
    //持失切
};

Init::~Init() {
    //社瑚切
}

Init::Init(HDC dcScreen) {
    //持失切
    int i;

    ////
    g_sfBack.CreateBackBuffer(dcScreen, 640, 480, 32);

    ////
    //g_sfBG-> = __MakeDDBFromDIB(dcScreen, "map.bmp");
    g_sfBG.SetHBmp(MakeDDBFromDIB(dcScreen, "map.bmp"));
    g_sfBG.LoadSurface(dcScreen);

    //
    //for (i = 0; i < 8; i++)
    //{
    //    __SetSprSurface(&(g_objCar[0].g_sfCar[i]), RGB(255, 0, 0));
    //    __SetSprSurface(&(g_objCar[1].g_sfCar[i]), RGB(255, 0, 0));
    //    wsprintf(strName, "car-%d.bmp", i + 1);
    //    g_objCar[0].g_sfCar[i].hBmp = __MakeDDBFromDIB(dcScreen, strName);
    //    g_objCar[1].g_sfCar[i].hBmp = __MakeDDBFromDIB(dcScreen, strName);
    //    __LoadSurface(dcScreen, &(g_objCar[0].g_sfCar[i]));
    //    __LoadSurface(dcScreen, &(g_objCar[1].g_sfCar[i]));
    //}
};

