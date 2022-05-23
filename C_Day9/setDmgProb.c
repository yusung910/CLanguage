void setDmgProb(float* nDmgProbList, int nTurn) {
	int nLevel = (nTurn < 900) ? (nTurn / 10) : 9;
	//������ ��� �ϱ� �� 20���� �Ѿ��
	//10�ϸ��� ������ Ȯ���� �����Ѵ�.
	if (nTurn > 10) {
		for (int o = 0; o < 5; o++) {
			int a = 10 - o;
			nDmgProbList[o] = (float)(1 - ((a + nLevel) * 0.01)) / 11;
			nDmgProbList[a] = (float)(1 + ((a + nLevel) * 0.01)) / 11;
		}
	}
}