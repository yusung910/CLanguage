#include "InitDisplay.h"

void InitDisplay(HWND hWnd, static int clientX, static int clientY) {
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(hWnd, &ps);
	hdc = BeginPaint(hWnd, &ps);
	// LineTo, PolyLineTo ���� �Լ��� ���� ���� ��ǥ�� ����Ѵ�
	MoveToEx(hdc, 0, 0, NULL);	// ���� ��ǥ�� �����ޱ� ���� POINT����ü�� ������
	// ���� ��ġ���� �������� ���� �ߴ´�. �̶� ������ ������ ���ܵȴ�
	LineTo(hdc, 0, clientX);
	EndPaint(hWnd, &ps);

}