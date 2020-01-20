/*************************************************************************
	> File Name: 1_string.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月26日 星期二 16时01分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class String {
public:
    String(const char *str = nullptr);
    String(const String &str);
    String &operator =(const String &str);
    ~String();
    
    void Show();

private:
    char *_mStr;
};

String::String(const char *str) {
    if(nullptr == str) {
        _mStr    = new char[1];
        _mStr[0] = '\0';
    }
    else {
        int len = strlen(str);
        _mStr = new char[len + 1];
        strncpy(_mStr, str, len);
        _mStr[len] = '\0';
    }

    std::cout << "构造函数" << std::endl;
}

String::String(const String &str) {
    int len = strlen(str._mStr);
    _mStr = new char[len + 1];
    strncpy(_mStr, str._mStr, len);
    _mStr[len] = '\0';

    std::cout << "拷贝构造函数" << std::endl;
}

String &String::operator =(const String &str) {
    if(this == &str) {
        return *this;
    }
    else {
        delete [] _mStr;
        int len = strlen(str._mStr);
        _mStr = new char[len + 1];
        strncpy(_mStr, str._mStr, len);
        _mStr[len] = '\0';
    }

    std::cout << "=号运算符" << std::endl;
}

String::~String() {
    delete [] _mStr; 
    std::cout << "析构函数" << std::endl;
}

void String::Show() {
    std::cout << "string = " << _mStr << std::endl;
}

int main(int argc, char *argv[]) {
    String str("hello, world");
    str.Show();
    String str1("你好");
    String str2(str);
    str2.Show();
    return 0;
}
