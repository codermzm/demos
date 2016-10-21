#include <QCoreApplication>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char ch[3][4] = { "AAA","BB","CCC" }, ( * q )[4] = ch, *p;
    int i;
    p = new char;
    *p = 'b';
    * ( *q + 3 ) = *p;
    for ( i = 0; i < 3; i++ ) {
        cout << q[i] << endl;
    }

    return a.exec();
}
