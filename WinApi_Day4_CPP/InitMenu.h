#pragma once
#include <windows.h>
#include "__debug.h"

class InitMenu {
public :
    //생성자
    InitMenu();
    //소멸자
    ~InitMenu();

    //클라이언트 크기 세팅
    void SetClientSize(HWND hWnd);

    //툴 버튼 그리기
    void DrawTool(HWND hWnd);

    //영역 그리기
    void DrawBoundary(HDC hdc, int(*n_posList)[4], int size);

    //마우스 위치 세팅
    BOOL GetMouseToolFlag(LPARAM lParam);

    //마우스 커서 위치가 tool 영역인지 확인
    BOOL GetPosFlag(int(*n_posList)[4], int size);

protected:
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;
    //윈도우 사이즈
    RECT winRec;

    int clientX, clientY;
    //마우스 커서 위치
    int n_mouseX, n_mouseY;

    //브러시 스타일 종류
    int nHS[6] = { HS_HORIZONTAL, HS_VERTICAL,
                   HS_BDIAGONAL,  HS_FDIAGONAL,
                   HS_CROSS,      HS_DIAGCROSS };
    //툴바 영역 높이
    int nToolBarHeight = 255;

    //버튼 사이즈
    int nToolBtnSize = 55;

    //미리보기 영역 사이즈
    int nPreviewSize = 200;

    //각각 영역의 시작 위치
    int nDrawToolBoundaryList[5][4] = {
        {30, 30, 30 + nToolBtnSize, 30 + nToolBtnSize},        //펜
        {90, 30, 90 + nToolBtnSize, 30 + nToolBtnSize},        //직선
        {150, 30, 150 + nToolBtnSize, 30 + nToolBtnSize},      //원
        {210, 30, 210 + nToolBtnSize, 30 + nToolBtnSize},      //사각형
        {270, 30, 270 + nToolBtnSize, 30 + nToolBtnSize},      //라운딩 사각형
    };

    int nLineToolBoundaryList[5][4] = {
        {30, 105, 30 + nToolBtnSize, 105 + nToolBtnSize},      //선 그리기 타입1
        {90, 105, 90 + nToolBtnSize, 105 + nToolBtnSize},      //선 그리기 타입2
        {150, 105, 150 + nToolBtnSize, 105 + nToolBtnSize},    //선 그리기 타입3
        {210, 105, 210 + nToolBtnSize, 105 + nToolBtnSize},    //선 그리기 타입4
        {270, 105, 270 + nToolBtnSize, 105 + nToolBtnSize},    //선 그리기 타입5
    };

    int nBrushToolBoundaryList[7][4] = {
        {30, 180, 30 + nToolBtnSize, 180 + nToolBtnSize},      //브러시 타입1
        {90, 180, 90 + nToolBtnSize, 180 + nToolBtnSize},      //브러시 타입2
        {150, 180, 150 + nToolBtnSize, 180 + nToolBtnSize},     //브러시 타입3
        {210, 180, 210 + nToolBtnSize, 180 + nToolBtnSize},     //브러시 타입4
        {270, 180, 270 + nToolBtnSize, 180 + nToolBtnSize},     //브러시 타입5
        {330, 180, 330 + nToolBtnSize, 180 + nToolBtnSize},     //브러시 타입6
        {390, 180, 390 + nToolBtnSize, 180 + nToolBtnSize},     //브러시 타입7
    };

    int nEraseToolBoundaryList[2][4] = {
        {1260, 180, 1260 + nToolBtnSize, 180 + nToolBtnSize},    //지우개
        {1325, 180, 1325 + nToolBtnSize, 180 + nToolBtnSize},    //전체 지우개
    };

    int nTextToolBtnPosList[3][4] = {
        {350, 50, 450, 70},
        {350, 90, 450, 110},
        {350, 130, 470, 150},
    };

    int nToolBoundaryList[5][4] = {
        {500, 30, 500 + nPreviewSize + 55, 30 + nPreviewSize},      //미리보기 영역
        {770, 30, 1070, 165},      //펜 RGB 스크롤 영역
        {1080, 30, 1380, 165},     //브러시 RGB 스크롤 영역
        {770, 180, 1050, 215},     //펜 두께 스크롤 영역
        {340, 30, 490, 160}, //문자열 출력 버튼 영역
    };
private:

};