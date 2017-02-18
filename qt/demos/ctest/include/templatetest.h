#ifndef TEMPLATETEST_H
#define TEMPLATETEST_H

template <class T>
void templatetest_change( T &t1, T &t2 ) {
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

#endif // TEMPLATETEST_H
