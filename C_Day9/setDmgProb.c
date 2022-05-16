void setDmgProb(float* nDmgProbList, int turn) {
	//난이도
	int nLevel = (turn < 900) ? turn / 10 : 89;

	//초기 세팅
	if(turn == 0){
		for (int o = 0; o < 11; o++) {
			nDmgProbList[o] = (float)1 / 11;
		}
	}

	//데미지 계산 하기 전 20턴이 넘어가고
	//10턴마다 데미지 확률을 변경한다.
	if (turn > 0 && (turn % 10 == 0)) {
		for (int o = 0; o < 5; o++) {
			int a = 10 - o;
			nDmgProbList[o] = (float)(1 - ((a + nLevel) * 0.01)) / 11;
			nDmgProbList[a] = (float)(1 + ((a + nLevel) * 0.01)) / 11;
		}
	}

}