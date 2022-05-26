#include <iostream>
#include "player.h"

int main()
{
    char pname[] = "플레이어1";
	CPlayer testPlayer(100, 100, pname);
    testPlayer.ShowStatus();
	return 0;
}
