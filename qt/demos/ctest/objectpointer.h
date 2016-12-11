#ifndef TIME_H
#define TIME_H

#include<iostream>

using namespace std;

class ObjectPointer {
    
public :
    ObjectPointer( int h, int m, int s ) {
        hour = h;
        minute = m;
        sec = s;
    }
    
    /**
     * 小时
     */
    int hour;
    
    /**
     * 分钟
     */
    int minute;
    
    /**
     * 秒
     */
    int sec;
    
    /**
     * 获取当前时间
     */
    void get_time( );
    
};

void ObjectPointer::get_time( ) {
    cout << hour << ":" << minute << ":" << sec << endl;    
}

void general( ){
    cout << "general" << endl;
}

static void objectpoint_exe( ) {
    
    //指向对象的指针
    ObjectPointer *pt;
    ObjectPointer t1(1,10,10);
    pt = &t1;
    (*pt).hour = 10;
    cout << pt->hour << endl;
    (*pt).get_time( );
    
    //指向对象成员变量的指针
    int *p1;
    p1 = &t1.hour;
    cout << *p1 << endl;
    
    //普通函数指针
    void (*general_p)();
    general_p = general;
    (*general_p)();
    
    //指向对象成员函数的指针
    void (ObjectPointer::*timer_func_p)();
    timer_func_p = &ObjectPointer::get_time;
    (t1.*timer_func_p)();
    
}


#endif // TIME_H
