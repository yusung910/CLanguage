#include "InitDisplay.h"

void InitDisplay(HWND hWnd, int clientX, int clientY, int n_barSize) {
    

    HDC hdc;
    PAINTSTRUCT ps;
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;

    static int nHS[6] = { HS_HORIZONTAL, HS_VERTICAL,
                          HS_BDIAGONAL,  HS_FDIAGONAL,
                          HS_CROSS,      HS_DIAGCROSS };

    hdc = BeginPaint(hWnd, &ps);
    
    newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
    oldPen = SelectObject(hdc, newPen);

    // LineTo, PolyLineTo 등의 함수가 선의 시작 좌표로 사용한다
    MoveToEx(hdc, 0, n_barSize, NULL);	// 이전 좌표를 돌려받기 위한 POINT구조체의 포인터
    // 현재 위치에서 끝점까지 선을 긋는다. 이때 끝점은 선에서 제외된다
    LineTo(hdc, clientX, n_barSize);

    //선택할 수 있는 메뉴 출력
    //펜 선택 버튼
    Rectangle(hdc, 30, 30, 85, 85);
    //직선 선택 버튼
    Rectangle(hdc, 90, 30, 145, 85);
    //원 선택 버튼
    Rectangle(hdc, 150, 30, 205, 85);
    //사각형 선택 버튼
    Rectangle(hdc, 210, 30, 265, 85);
    //라운딩 사각형 선택 버튼
    Rectangle(hdc, 270, 30, 325, 85);

    //선그리기 타입1
    Rectangle(hdc, 30, 105, 85, 160);
    //선그리기 타입2
    Rectangle(hdc, 90, 105, 145, 160);
    //선그리기 타입3
    Rectangle(hdc, 150, 105, 205, 160);
    //선그리기 타입4
    Rectangle(hdc, 210, 105, 265, 160);
    //선그리기 타입5
    Rectangle(hdc, 270, 105, 325, 160);

    //브러시1
    Rectangle(hdc, 30, 180, 85, 235);
    //브러시2
    Rectangle(hdc, 90, 180, 145, 235);
    //브러시3
    Rectangle(hdc, 150, 180, 205, 235);
    //브러시4
    Rectangle(hdc, 210, 180, 265, 235);
    //브러시5
    Rectangle(hdc, 270, 180, 325, 235);
    //브러시6
    Rectangle(hdc, 330, 180, 385, 235);
    //브러시7
    Rectangle(hdc, 390, 180, 445, 235);

    //미리보기 영역 그리기
    Rectangle(hdc, 500, 30, 750, 235);

    //펜 RGB 영역 그리기
    Rectangle(hdc, 770, 30, 1070, 165);

    //브러시 RGB 영역 그리기
    Rectangle(hdc, 1080, 30, 1380, 165);

    //펜 두께 스크롤 영역 그리기
    Rectangle(hdc, 770, 180, 1050, 215);

	//지우개
	Rectangle(hdc, 1260, 180, 1315, 235);
	//화면지우기
	Rectangle(hdc, 1325, 180, 1380, 235);

    //문자열 디자인 영역
    Rectangle(hdc, 340, 30, 490, 160);

    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);

    //미리보기 타이틀 출력
    TextOut(hdc, 520, 23, "미리보기", 8);

	//지우개 타이틀 출력
	TextOut(hdc, 1264, 200, "지우개", 6);

	//전채지우개 타이틀 출력
	TextOut(hdc, 1329, 200, "초기화", 6);

    //텍스트 출력 스타일 타이틀 출력
    TextOut(hdc, 345, 25, "텍스트 스타일", 13);
    TextOut(hdc, 350, 50, "기본 문자 배경", 14);
    TextOut(hdc, 350, 90, "투명 문자 배경", 14);
    TextOut(hdc, 350, 130, "불투명 문자 배경", 16);

    //펜 RGB 타이틀 출력
    TextOut(hdc, 780, 23, "펜 RGB", 6);
    SetTextColor(hdc, RGB(255, 0, 0));
    TextOut(hdc, 780, 52, "R", 1);
    SetTextColor(hdc, RGB(0, 255, 0));
    TextOut(hdc, 780, 92, "G", 1);
    SetTextColor(hdc, RGB(0, 0, 255));
    TextOut(hdc, 780, 132, "B", 1);

    //펜 RGB 타이틀 출력
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOut(hdc, 1090, 23, "브러시 RGB", 10);
    SetTextColor(hdc, RGB(255, 0, 0));
    TextOut(hdc, 1090, 52, "R", 1);
    SetTextColor(hdc, RGB(0, 255, 0));
    TextOut(hdc, 1090, 92, "G", 1);
    SetTextColor(hdc, RGB(0, 0, 255));
    TextOut(hdc, 1090, 132, "B", 1);

    //펜 두께 스크롤 타이틀 출력
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOut(hdc, 780, 170, "펜 두께", 7);

    //펜 아이콘 그리기
    MoveToEx(hdc, 35, 35, NULL);
    LineTo(hdc, 45, 50);
    LineTo(hdc, 55, 60);
    LineTo(hdc, 65, 70);
    LineTo(hdc, 80, 80);

    //직선 그리기
    MoveToEx(hdc, 95, 35, NULL);
    LineTo(hdc, 140, 80);

    //원 그리기
    Ellipse(hdc, 155, 35, 200, 80);

    //사각형 그리기
    Rectangle(hdc, 215, 35, 260, 80);

    //타원사각형
    RoundRect(hdc, 275, 35, 320, 80, 10, 10);

    //선 유형1 아이콘 그리기
    MoveToEx(hdc, 155, 110, NULL);
    LineTo(hdc, 200, 155);

    //선 유형2 아이콘 그리기
    newPen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 35, 110, NULL);
    LineTo(hdc, 80, 155);

    //선 유형3 아이콘 그리기
    newPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 95, 110, NULL);
    LineTo(hdc, 140, 155);

    //선 유형4 아이콘 그리기
    newPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 215, 110, NULL);
    LineTo(hdc, 260, 155);

    //선 유형5 아이콘 그리기
    newPen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 275, 110, NULL);
    LineTo(hdc, 320, 155);

    //브러시 유형 아이콘 그리기
    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);

    SelectObject(hdc, GetStockObject(BLACK_BRUSH));
    Ellipse(hdc, 35, 185, 80, 230);

    //브러쉬 유형1 아이콘 그리기
    for (int i = 0; i < 6;i++) {
        int n_icon = ((i + 1) * 60 ) + 35;
        newBrush = CreateHatchBrush(nHS[i], RGB(0, 0, 0));
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        Ellipse(hdc, n_icon, 185, (n_icon + 45), 230);
        SelectObject(hdc, oldBrush);
        DeleteObject(newBrush);
    }

    SelectObject(hdc, oldPen);

    DeleteObject(newPen);



    EndPaint(hWnd, &ps);

    
}