#include <QCoreApplication>
#include <iostream>
#include <QTextCodec>

#include "arraypoint.h"
#include "templatetest.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale( ));
    
    /**
     * 数组指针
     */
    ArrayPoint *arrayPoint = new ArrayPoint;
    arrayPoint->test( );

    int num1 = 3, num2 = 4;
    templatetest_change<int>( num1, num2 );
    cout << "num1 -> " << num1 << ",num2 -> " << num2 << endl;
    
    char char1 = 'a',char2 = 'b';
    templatetest_change<char>( char1, char2 );
    cout << "char1 -> " << char1 << ",char2 -> " << char2 << endl;
    
    cout << "execution is done" << endl;
    
    return a.exec();
}
