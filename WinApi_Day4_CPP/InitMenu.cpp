#include "InitMenu.h"

InitMenu::InitMenu() {
    //생성자

}

InitMenu::~InitMenu() {
    //소멸자
}

void InitMenu::SetClientSize(HWND hWnd) {
    //클라이언트 사이즈를 계산한다.
    GetClientRect(hWnd, &winRec);
    clientX = winRec.right;
    clientY = winRec.bottom;
}



void InitMenu::DrawTool(HWND hWnd) {
    hdc = BeginPaint(hWnd, &ps);

    newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
    oldPen = (HPEN) SelectObject(hdc, newPen);

    // LineTo, PolyLineTo 등의 함수가 선의 시작 좌표로 사용한다
    MoveToEx(hdc, 0, nToolBarHeight, NULL);	// 이전 좌표를 돌려받기 위한 POINT구조체의 포인터
    // 현재 위치에서 끝점까지 선을 긋는다. 이때 끝점은 선에서 제외된다
    LineTo(hdc, clientX, nToolBarHeight);

    //선택할 수 있는 메뉴 영역 출력
    DrawBoundary(hdc, nDrawToolBoundaryList, ((sizeof(nDrawToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nLineToolBoundaryList, ((sizeof(nLineToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nBrushToolBoundaryList, ((sizeof(nBrushToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nEraseToolBoundaryList, ((sizeof(nToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nToolBoundaryList, ((sizeof(nToolBoundaryList)) / 4) / 4);
    
    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = (HPEN)SelectObject(hdc, newPen);

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
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 35, 110, NULL);
    LineTo(hdc, 80, 155);

    //선 유형3 아이콘 그리기
    newPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 95, 110, NULL);
    LineTo(hdc, 140, 155);

    //선 유형4 아이콘 그리기
    newPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 215, 110, NULL);
    LineTo(hdc, 260, 155);

    //선 유형5 아이콘 그리기
    newPen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 275, 110, NULL);
    LineTo(hdc, 320, 155);

    //브러시 유형 아이콘 그리기
    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);

    SelectObject(hdc, GetStockObject(BLACK_BRUSH));
    Ellipse(hdc, 35, 185, 80, 230);

    //브러쉬 유형1 아이콘 그리기
    for (int i = 0; i < 6; i++) {
        int n_icon = ((i + 1) * 60) + 35;
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

void InitMenu::DrawBoundary(HDC hdc, int(*n_posList)[4], int size) {
    for (int i = 0; i < size; i++) {
        Rectangle(hdc, n_posList[i][0], n_posList[i][1], n_posList[i][2], n_posList[i][3]);
    }
}

BOOL InitMenu::GetMouseToolFlag(LPARAM lParam) {
    BOOL retBool = FALSE;
    n_mouseX = (short)LOWORD(lParam);
    n_mouseY = (short)HIWORD(lParam);

    if (GetPosFlag(nDrawToolBoundaryList, ((sizeof(nDrawToolBoundaryList)) / 4) / 4) || 
        GetPosFlag(nLineToolBoundaryList, ((sizeof(nLineToolBoundaryList)) / 4) / 4) ||
        GetPosFlag(nBrushToolBoundaryList, ((sizeof(nBrushToolBoundaryList)) / 4) / 4) ||
        GetPosFlag(nTextToolBtnPosList, ((sizeof(nTextToolBtnPosList)) / 4) / 4)) {
        SetCursor(LoadCursor(NULL, IDC_HAND));
        retBool = TRUE;
    }

    return retBool;
};

BOOL InitMenu::GetPosFlag(int(*n_posList)[4], int size) {
    BOOL retBool = FALSE;
    for (int i = 0; i < size; i++) {
        if (n_mouseX > n_posList[i][0] &&
            n_mouseX < n_posList[i][2] &&
            n_mouseY > n_posList[i][1] &&
            n_mouseY < n_posList[i][3]) {
            retBool = TRUE;
        }
    }

    return retBool;
}