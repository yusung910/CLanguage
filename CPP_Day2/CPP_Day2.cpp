#include <iostream>
#include <conio.h>
#include "player.h"

using namespace std;


int main()
{
	char pname1[] = "플레이어1";
	char pname2[] = "플레이어2";
	char pname3[] = "플레이어3";
	CPlayer testPlayer1(100, 100, pname1), testPlayer2(100, 100, pname2), testPlayer3(100, 100, pname3);
	testPlayer1.ShowStatus();
	testPlayer2.ShowStatus();
	testPlayer3.ShowStatus();
	printf("====================================\n");
	cout << "총 유저 수 : " << testPlayer1.GetUserCnt() << endl;
	return 0;
}
