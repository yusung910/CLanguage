#include <iostream>
#include "Str.h"
using namespace std;
int main()
{
    String test1("히어로", 10);
    String test2("히어로", 90);
    String test3("히어로", 98);

    test1.Display();
    test2.Display();
    test3.Display();

    test2 = test3;
    test2.Display();

    String test[10] = { 
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
        String("히어로", 100),
    };

	for (int i = 0; i < 10; i++) {
		test[i].Display();
	}

}
