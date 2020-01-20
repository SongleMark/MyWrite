/*************************************************************************
	> File Name: test.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2020年01月09日 星期四 10时08分22秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Father {
public:
    Father() {}
    virtual ~Father() {
        cout << "this is Father's delete function" << endl;
    }
    virtual void test() {
        cout << "this is father's test function" << endl;
    }
};

class Son : public Father
{
public:
    Son() {}
    ~Son() {
        cout << "this is Son's delete funtion" << endl;
    }
    void test() {
        cout << "this is son's test function" << endl;
    }

};

int main(int argc, char *argv[]) {
    Father *ptr = new Son(); 
    ptr->test();
    delete ptr; // 当基类的析构函数为虚函数时执行delete操作会执行子类的析构函数，否则仅仅执行自身的析构函数不执行子类的析构函数

    return 0;
}
