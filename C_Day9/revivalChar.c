#pragma once
#include <malloc.h>
#include "characterStruct.h"
#include "revivalChar.h"

int revivalChar(CHARACTER* charList[100], int nDeathNum) {

	//사망 플레이어를 저장하기위한 배열
	int* nDeathNote;

	//부활 유저 수
	int nResurection = 0;

	//매 턴 마다 발생한 사망자의 수 만큼 동적 배열을 생성
	//동적 배열을 이용하여 생성 한 이유는
	//기존에 저장된 사망자 명단을 한번 초기화 해줘야 할 필요가 있기 때문.
	//기존의 배열(int d[100])을 이용하여 생성 할 경우
	//기존에 죽은 유저가 남아 있음
	//죽은 유저는 얼마든지 부활 할 수 있기 때문에
	//매 turn마다 사망자 목록을 초기화 해야함.
	nDeathNote = (int*)malloc((nDeathNum + 1) * sizeof(int));
	//생성된 배열에 사망자를 저장한다.
	int nDeathNoteArry = 0;
	for (int f = 0; f < 100; f++) {
		if (charList[f] == NULL) {
			nDeathNote[nDeathNoteArry] = f;
			nDeathNoteArry += 1;
		}
	}
	//사망자 중 10퍼센트 부활 한다.
	nResurection = nDeathNum / 10;
	//부활 시킬 대상자 수 만큼 반복문을 실행.            
	for (int c = 0; c < nResurection; c++) {
		//0부터 사망한 인원 수 사이의 임의의 수를 생성
		int nPlayer = rand() % nDeathNoteArry;
		//임의의 수에 저장된 유저 인덱스에 character 구조체를 동적으로 다시 생성한다.
		charList[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
		charList[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
		charList[nDeathNote[nPlayer]]->nDamage = 0;
	}
	//사망한 플레이어의 목록이 저장된 데이터 배열을 해제한다,
	//배열을 메모리에서 해재함으로 써 기존의 데이터를 초기화한다.
	free(nDeathNote);

	//부활한 캐릭터 수를 리턴한다.
	return nResurection;
}