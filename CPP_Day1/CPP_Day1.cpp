#include <iostream>

using namespace std;

struct playersInfo {
	int hp;
	char name[100];
};

namespace Calculator {

	int sum(int a, int b) {
		return a + b;
	}

	int mul(int a, int b) {
		return a * b;
	}

	int min(int a, int b) {
		return a - b;
	}

	float division(int a, int b) {
		return (float) a / b;
	}

	void initCharInfo(playersInfo pinfo) {
		pinfo.hp = 100;
		pinfo.name = "플레이어1";

	}
}

using namespace Calculator;

int main()
{
    cout << "Sum :: " << sum(10, 11) << endl;
	cout << "mul :: " << mul(10, 11) << endl;
	cout << "min :: " << min(10, 11) << endl;
	cout << "div :: " << division(10, 11) << endl;
}
