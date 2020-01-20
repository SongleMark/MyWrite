#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

class String
{
public:
    // [构造函数]
    //String(); // <1>
    String(const char *str = nullptr); // 参数默认为nullptr后则无需写<1>
    String(const String &string);
    // [运算符重载]
    String &operator = (const String &string);
    String operator + (const String &string);
    friend ostream & operator << (ostream &out, const String &string);
    friend istream & operator >> (istream &input, String &string);
    bool operator ==(const String &string);
    bool operator >(const String &string);
    bool operator <(const String &string);
    char operator [](int index);
	// [相关函数]
	String &append(const char *str);

private:
    char *mStr;
};

#if 0
/// 构造函数
String::String() {
    mStr = new char[1];
    mStr[0] = '\0';
    printf("构造函数\n");
}
#endif

/// 构造函数
String::String(const char *str) {
    if(nullptr == str) {
        mStr = new char[1];
        mStr[0] = '\0';
    }
    else {
        int length = strlen(str);
        mStr = new char[length + 1];
        strncpy(mStr, str, length);
        mStr[length] = '\0';
    }
    std::cout << "调用构造函数" << std::endl;
}

/// 拷贝构造函数
/// 1.用一个对象初始化另一个对象
/// 2.对象作为引用传递
/// 3.返回一个临时对象或静态对象
String::String(const String &string) {
    int length = strlen(string.mStr);
    mStr = new char[length + 1];
    strncpy(mStr, string.mStr, length);
    mStr[length] = '\0';
    printf("调用拷贝构造函数\n");
}

/// =号运算符重载
String &String::operator=(const String &string) {
    if(this == &string) {
        return *this;
    }
    else {
        delete [] mStr;
        int length = strlen(string.mStr);
        mStr = new char[length + 1];
        strncpy(mStr, string.mStr, length);
        mStr[length] = '\0';
    }
    printf("=号运算符重载\n");

    return *this;
}

/// +号运算符重载
String String::operator+(const String &string) {
    String deststr;
    delete [] deststr.mStr;
    // 开辟空间为二者strlen长度相加
    int length = strlen(string.mStr) + strlen(mStr);
    deststr.mStr = new char[length + 1];
    memset(deststr.mStr, 0, length + 1); // 每个字符置为0
    // 现将原string的字符拷贝，然后拼接后来加上的字符
    strncpy(deststr.mStr, mStr, strlen(mStr));
    strncat(deststr.mStr, string.mStr, strlen(string.mStr));
    deststr.mStr[length] = '\0';

    return deststr;
}

/// <<号运算符重载
/// 注意: << 与 >> 号运算符重载函数只可写成友元函数
ostream &operator <<(ostream &out, const String &string) {
    out << string.mStr << endl;
    printf("<< 运算符重载\n");
    return out;
}

// >> 号运算符重载
istream &operator >>(istream &input, String &string) {
    input >> string.mStr;
    printf(">> 运算符重载\n");
    return input;
}

// == 号运算符重载
bool String::operator==(const String &string) {
    bool result = true;
    if(0 == strncmp(mStr, string.mStr, strlen(mStr))) {
        result = true;
    } 
    else {
        result = false;
    }

    return result;
}

// > 号运算符重载
bool String::operator >(const String &string) {
    bool result = true;
    if(strncmp(mStr, string.mStr, strlen(string.mStr)) > 0) {
        result = true;
    }
    else {
        result = false;
    }

    return result;
}

// < 号运算符重载
bool String::operator<(const String &string) {
    bool result = true;
    if(strncmp(mStr, string.mStr, strlen(string.mStr)) < 0) {
        result = true;
    }
    else {
        result = false;
    }

    return result;
}

// [] 号运算符重载
char String::operator[](int index) {
    return mStr[index];
}

// append() 
String &String::append(const char *str) {
	strcat(mStr, str);
	return *this;
}

int main(int argc, char *argv[]) {
    String str("hello, world"); // 调用构造函数
    String str1(str);           // 调用拷贝构造函数
    String s;                   // 调用构造函数
    String str2 = str1;         // 调用拷贝构造函数
    String str3 = str2 + str1;  // 调用构造函数
    cout << "str3 = " << str3 ; // <<
    cout << "请输入:";
    String str4;
    cin >> str4;
    cout << "str4 = " << str4;
    cout << "str4[3] = " << str4[3] << endl;

	str2.append("abc");
	cout << "str2 = " << str2 ;
}
