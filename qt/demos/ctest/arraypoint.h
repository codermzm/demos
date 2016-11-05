#ifndef ARRAYPOINT_H
#define ARRAYPOINT_H

#include <iostream>

/**
 *测试C++的数组指针
 **/
using namespace std;

class ArrayPoint {

public :
    void test( );

};

void ArrayPoint::test() {
    char ch[3][4] = { "AAA","BB","CCC" }, ( * q )[4] = ch, *p;
    int i;
    p = new char;
    *p = 'b';
    * ( *q + 3 ) = *p;
    for ( i = 0; i < 3; i++ ) {
        cout << q[i] << endl;
    }
}


#endif // ARRAYPOINT_H
