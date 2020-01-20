/*************************************************************************
	> File Name: stdString.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月20日 星期三 16时02分59秒
 ************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

class String{
public:
    // [构造/析构函数]
    String(const char *str = nullptr);
    String(const String &string);
    ~String();
    // [运算符重载]
    String &operator =(const String &string);
    friend ostream &operator <<(ostream &out, const String &string); 
    friend istream &operator >>(istream &input, String string);

    // [打印]
    void Show();

private:
    char *_mStr;
};

/**
 * 构造函数
 */
String::String(const char *str) {
    if(nullptr == str) {
        _mStr = new char[1];
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

/**
 *拷贝构造函数
 */
String::String(const String &string) {
    int len = strlen(string._mStr);
    _mStr = new char[len + 1];
    strncpy(_mStr, string._mStr, len);
    _mStr[len] = '\0';

    std::cout << "拷贝构造函数" << std::endl;
}

String::~String() {
    delete [] _mStr;
}

String &String::operator =(const String &string) {
    if(this == &string) {
        return *this;
    }   
    else {
        delete [] _mStr;
        int len = strlen(string._mStr);
        _mStr = new char[len + 1];
        strncpy(_mStr, string._mStr, len);
        _mStr[len] = '\0';
    }

    std::cout << "=号运算符重载" << std::endl;
}

ostream &operator <<(ostream &out, const String &string) {
    out << "string = " << string._mStr << std::endl;
    printf(" << 运算符重载\n");
    return out;
}

istream &operator >>(istream &input, String string) {
    input >> string._mStr;
    printf(" >> 运算符重载\n");
    return input;
}

void String::Show() {
    std::cout << "string = " << _mStr << std::endl;
}

int main(int argc, char *argv[]) {
    String str("hello, world");
    str.Show();

    String str1 = str;
    str1.Show();
    
    std::cout << str1;
    std::cin >> str;
    std::cout << str;

    return 0;
}
