#include "String.h"

using namespace std;
void main() {

	String test("�׽�Ʈ ���ڿ�");
	String str = "���ڿ� �׽�Ʈ";
	String str3 = "���ڿ� ����";
	test.Display();
	test = test + " ���ڿ� �����̱�";
	cout << endl;
	test.Display();
	cout << endl;
	str3 = test + str;
	str3.Display();
	
}