#include "SetTool.h";
BOOL SetTool(int x, int y) {
	int n_tool = -1;
	
	//�� ���� ��ư
	if (x > 30 && x < 85 && y > 30 && y < 85) {
		//�� ���� ��ư
		n_tool = 0;
	}
	else if (x > 90 && x < 145 && y > 30 && y < 85) {
		//���� ���� ��ư
		n_tool = 1;
	}
	else if (x > 150 && x < 205 && y > 30 && y < 85) {
		//�� ���� ��ư
		n_tool = 2;
	}
	else if (x > 210 && x < 265 && y > 30 && y < 85) {
		//�簢�� ���� ��ư
		n_tool = 3;
	}
	else if (x > 270 && x < 325 && y > 30 && y < 85) {
		//���� �簢�� ���� ��ư
		n_tool = 4;
	}
	else if (x > 30 && x < 85 && y > 105 && y < 160) {
		//���׸��� Ÿ��1
		n_tool = 5;
	}
	else if (x > 90 && x < 145 && y > 105 && y < 160) {
		//���׸��� Ÿ��2
		n_tool = 6;
	}
	else if (x > 150 && x < 205 && y > 105 && y < 160) {
		//���׸��� Ÿ��3
		n_tool = 7;
	}
	else if (x > 210 && x < 265 && y > 105 && y < 160) {
		//���׸��� Ÿ��4
		n_tool = 8;
	}
	else if (x > 270 && x < 325 && y > 105 && y < 160) {
		//���׸��� Ÿ��5
		n_tool = 9;
	}
	else if (x > 30 && x < 85 && y > 180 && y < 235) {
		//�귯��1
		n_tool = 10;
	}
	else if (x > 90 && x < 145 && y > 180 && y < 235) {
		//�귯��2
		n_tool = 11;
	}
	else if (x > 150 && x < 205 && y > 180 && y < 235) {
		//�귯��3
		n_tool = 12;
	}
	else if (x > 210 && x < 265 && y > 180 && y < 235) {
		//�귯��4
		n_tool = 13;
	}
	else if (x > 270 && x < 325 && y > 180 && y < 235) {
		//�귯��5
		n_tool = 14;
	}
	else if (x > 330 && x < 385 && y > 180 && y < 235) {
		//�귯��6
		n_tool = 15;
	}
	else if (x > 390 && x < 445 && y > 180 && y < 235) {
		//�귯��7
		n_tool = 16;
	}
	else if (x > 1260 && x < 1315 && y > 180 && y < 235) {
		//���찳
		n_tool = 17;
	}
	else if (x > 1325 && x < 1380 && y > 180 && y < 235) {
		//���찳
		n_tool = 18;
	}

	return (n_tool > -1) ? TRUE : FALSE;
}