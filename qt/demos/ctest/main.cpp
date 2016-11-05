#include <QCoreApplication>
#include <iostream>

#include "arraypoint.h"
#include "templatetest.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /**
     * 数组指针
     */
    ArrayPoint *arrayPoint = new ArrayPoint;
    arrayPoint->test( );

    int num1 = 3, num2 = 4;
    templatetest_change<int>( num1, num2 );
    

    return a.exec();
}
