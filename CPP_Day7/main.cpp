#include "String.h"

using namespace std;
void main() {

	String test("테스트 문자열");
	String str = "문자열 테스트";
	String str3 = "문자열 대입";
	test.Display();
	test = test + " 문자열 덧붙이기";
	cout << endl;
	test.Display();
	cout << endl;
	str3 = test + str;
	str3.Display();
	
}