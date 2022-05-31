#include <iostream>
#include "Str.h"
int main()
{
    String test1("히어로", 100);
    String test2("히어로", 100);
    String test3("히어로", 100);
    test1.Display();
    test2.Display();
    test3.Display();

    test2 = test3;
    test2.Display();
}
