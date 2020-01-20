
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

class String {
public:
    explicit String(const char *str = nullptr);
    explicit String(const String &str);
    ~String();
    void Show();

private:
    char *mStr;
};

String::String(const char *str) {
    if(nullptr == str) {
        mStr = new char[1];
        mStr[0] = '\0';
    }
    else {
        int len = strlen(str);
        mStr = new char[len + 1];
        strncpy(mStr, str, len);
        mStr[len] = '\0';
    }

    std::cout << "构造函数" << std::endl;
}

String::String(const String &str) {
    int len = strlen(str.mStr);
    mStr = new char[len + 1];
    strncpy(mStr, str.mStr, len);
    mStr[len] = '\0';

    std::cout << "深拷贝" << std::endl;
}

String::~String() {
    if(mStr) {
        delete mStr;
        mStr = nullptr;
    }
    std::cout << "析构函数" << std::endl;
}

void String::Show() {
    std::cout << "string = " << mStr << std::endl;
}

int main(int argc, char *argv[]) {
    String str("hello, world");
    str.Show();

    return 0;
}

