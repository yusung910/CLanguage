#include <stdio.h>
#include "cnst.h"

int setResurrectionChar(CHARACTER** players, int nDeathUserCnt) {

	//매 턴 마다 발생한 사망자의 수 만큼 동적 배열을 생성
	//동적 배열을 이용하여 생성 한 이유는
	//기존에 저장된 사망자 명단을 한번 초기화 해줘야 할 필요가 있기 때문.
	//기존의 배열(int d[100])을 이용하여 생성 할 경우
	//기존에 죽은 유저가 남아 있음
	//죽은 유저는 얼마든지 부활 할 수 있기 때문에
	//매 turn마다 사망자 목록을 초기화 해야함.
	int* nDeathNote = (int*)malloc(sizeof(int) * (nDeathUserCnt));
	int nResurection;
	//사망 캐릭터 수 카운팅하고
	//사망한 캐릭터가 있을 경우
	//해당 수만큼 동적 int 배열을 생성한 후
	//사망 캐릭터 번호를 int 배열에 저장한다.
	int nDeathCharNum = 0;
	for (int a = 0; a < 100; a++) {
		if (players[a] == NULL) {
			nDeathNote[nDeathCharNum] = a;
			nDeathCharNum += 1;
		}
	}

	//사망자 중 10퍼센트 부활 한다.
	nResurection = nDeathUserCnt / 10;

	//부활 시킬 대상자 수 만큼 반복문을 실행.            
	for (int c = 0; c < nResurection; c++) {
		//0부터 사망한 인원 수 사이의 임의의 수를 생성
		int nPlayer = rand() % nDeathUserCnt;
		//임의의 수에 저장된 유저 인덱스에 character 구조체를 동적으로 다시 생성한다.
		players[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
		players[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
		players[nDeathNote[nPlayer]]->nDamage = 0;
	}

	//배열을 메모리에서 해재함으로 써 기존의 데이터를 초기화한다.
	free(nDeathNote);

	return nResurection;
}