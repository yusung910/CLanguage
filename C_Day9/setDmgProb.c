void setDmgProb(float* nDmgProbList, int nTurn) {
	int nLevel = (nTurn < 900) ? (nTurn / 10) : 9;
	//데미지 계산 하기 전 20턴이 넘어가고
	//10턴마다 데미지 확률을 변경한다.
	if (nTurn > 10) {
		for (int o = 0; o < 5; o++) {
			int a = 10 - o;
			nDmgProbList[o] = (float)(1 - ((a + nLevel) * 0.01)) / 11;
			nDmgProbList[a] = (float)(1 + ((a + nLevel) * 0.01)) / 11;
		}
	}
}