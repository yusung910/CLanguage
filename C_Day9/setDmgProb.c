void setDmgProb(float* nDmgProbList, int turn) {
	//���̵�
	int nLevel = (turn < 900) ? turn / 10 : 89;

	//�ʱ� ����
	if(turn == 0){
		for (int o = 0; o < 11; o++) {
			nDmgProbList[o] = (float)1 / 11;
		}
	}

	//������ ��� �ϱ� �� 20���� �Ѿ��
	//10�ϸ��� ������ Ȯ���� �����Ѵ�.
	if (turn > 0 && (turn % 10 == 0)) {
		for (int o = 0; o < 5; o++) {
			int a = 10 - o;
			nDmgProbList[o] = (float)(1 - ((a + nLevel) * 0.01)) / 11;
			nDmgProbList[a] = (float)(1 + ((a + nLevel) * 0.01)) / 11;
		}
	}

}