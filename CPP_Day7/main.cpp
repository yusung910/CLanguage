#include <iostream>
#include "CSystem.h"
#include "Player.h"
#include "HashMap.h"


using namespace std;

void main() {
    //시스템 객체 생성
    //CSystem sys;
    HashMap<int, String, int> hm;


    String list[5] = {
        String("String1"),
        String("String2"),
        String("String3"),
        String("String4"),
        String("String5"),
    };

    int test[5] = { 1,2,3,4,5 };

    hm.Put(list, test, 5);
    hm.Put(1, "테스트", 5);
    hm.Put(6, "테스트7", 5);

    hm.GetValue(6).Display();
}