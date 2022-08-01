#include "InitDisplay.h"

void InitDisplay(HWND hWnd, static int clientX, static int clientY) {
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(hWnd, &ps);
	hdc = BeginPaint(hWnd, &ps);
	// LineTo, PolyLineTo 등의 함수가 선의 시작 좌표로 사용한다
	MoveToEx(hdc, 0, 0, NULL);	// 이전 좌표를 돌려받기 위한 POINT구조체의 포인터
	// 현재 위치에서 끝점까지 선을 긋는다. 이때 끝점은 선에서 제외된다
	LineTo(hdc, 0, clientX);
	EndPaint(hWnd, &ps);

}