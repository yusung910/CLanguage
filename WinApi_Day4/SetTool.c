#include "SetTool.h";
BOOL SetTool(int x, int y) {
	int n_tool = -1;
	
	//펜 선택 버튼
	if (x > 30 && x < 85 && y > 30 && y < 85) {
		//펜 선택 버튼
		n_tool = 0;
	}
	else if (x > 90 && x < 145 && y > 30 && y < 85) {
		//직선 선택 버튼
		n_tool = 1;
	}
	else if (x > 150 && x < 205 && y > 30 && y < 85) {
		//원 선택 버튼
		n_tool = 2;
	}
	else if (x > 210 && x < 265 && y > 30 && y < 85) {
		//사각형 선택 버튼
		n_tool = 3;
	}
	else if (x > 270 && x < 325 && y > 30 && y < 85) {
		//라운딩 사각형 선택 버튼
		n_tool = 4;
	}
	else if (x > 30 && x < 85 && y > 105 && y < 160) {
		//선그리기 타입1
		n_tool = 5;
	}
	else if (x > 90 && x < 145 && y > 105 && y < 160) {
		//선그리기 타입2
		n_tool = 6;
	}
	else if (x > 150 && x < 205 && y > 105 && y < 160) {
		//선그리기 타입3
		n_tool = 7;
	}
	else if (x > 210 && x < 265 && y > 105 && y < 160) {
		//선그리기 타입4
		n_tool = 8;
	}
	else if (x > 270 && x < 325 && y > 105 && y < 160) {
		//선그리기 타입5
		n_tool = 9;
	}
	else if (x > 30 && x < 85 && y > 180 && y < 235) {
		//브러시1
		n_tool = 10;
	}
	else if (x > 90 && x < 145 && y > 180 && y < 235) {
		//브러시2
		n_tool = 11;
	}
	else if (x > 150 && x < 205 && y > 180 && y < 235) {
		//브러시3
		n_tool = 12;
	}
	else if (x > 210 && x < 265 && y > 180 && y < 235) {
		//브러시4
		n_tool = 13;
	}
	else if (x > 270 && x < 325 && y > 180 && y < 235) {
		//브러시5
		n_tool = 14;
	}
	else if (x > 330 && x < 385 && y > 180 && y < 235) {
		//브러시6
		n_tool = 15;
	}
	else if (x > 390 && x < 445 && y > 180 && y < 235) {
		//브러시7
		n_tool = 16;
	}
	else if (x > 1260 && x < 1315 && y > 180 && y < 235) {
		//지우개
		n_tool = 17;
	}
	else if (x > 1325 && x < 1380 && y > 180 && y < 235) {
		//지우개
		n_tool = 18;
	}

	return (n_tool > -1) ? TRUE : FALSE;
}