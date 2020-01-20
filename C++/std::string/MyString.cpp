#include <iostream>
#include <cstdio>
#include <cstring>

/******************************************
 *std::string类相关函数的重写
 ******************************************/

class String
{
public:
	//构造
	String(const char *str = nullptr);
	String(const String &str);
	//运算符重载
	String &operator = (const String &str);
	String operator + (const String &str);
	bool operator == (const String &str);
	bool operator > (const String &str);
	bool operator < (const String &str);
	char &operator [] (const int &index);
	//析构
	~String(void);
	//打印
	void Show();

private:
	char *mString;
};

//构造函数
String::String(const char *str)
{
	int length;

	if(nullptr == str)
	{
		mString = new char[1];
		*mString = '\0';
	}
	else
	{
		length = strlen(str);
		mString = new char[length + 1];
		strncpy(mString, str, length );
		mString[length] = '\0';
	}
	std::cout << "构造函数" << std::endl;
}


/*******************************************
 *拷贝构造函数:
 *1.用一个对象初始化另一个对象
 *2.对象作为函数参数传递(引用)
 *3.返回一个临时对象，返回一个静态对象
 *******************************************/
//深拷贝
String::String(const String &str)
{
	int length = strlen(str.mString);
	mString = new char[length + 1];
	strncpy(mString, str.mString, length);
	mString[length] = '\0';

	std::cout << "拷贝构造函数" << std::endl;
}

// = 运算符重载
String &String::operator = (const String &str)
{
	int length;
	std::cout << "=运算符重载..." << std::endl;
	//如果是自身赋值
	if(this == &str)
	{
		return *this;
	}
	else
	{
		//先删除自身已经开辟了的空间
		delete [] mString;
		length = strlen(str.mString);
		this->mString = new char [length + 1];
		strncpy(this->mString, str.mString, length);
		mString[length] = '\0';
	}

	return *this;
}

// + 运算符重载
String String::operator + (const String &str)
{

	String addstring;
	int length = strlen(str.mString) + strlen(this->mString);
	delete [] addstring.mString;
	addstring.mString = new char[length + 1];
	memset(addstring.mString, 0, length + 1);

	strncpy(addstring.mString, this->mString, strlen(this->mString));
	//strncat(addstring.mString, str.mString, strlen(str.mString));
	strcat(addstring.mString, str.mString);
	addstring.mString[length] = '\0';

	return addstring;
}

// == 运算符重载
bool String::operator == (const String &str)
{
	bool result = true;
	if(0 == strcmp(this->mString, str.mString))
	{
		result = true;
	}
	else
	{
		result = false;
	}
	std::cout << "==运算符重载函数..." << std::endl;

	return result;
}

// > 运算符重载
bool String::operator > (const String &str)
{
	bool result = true;
	if(strcmp(this->mString, str.mString) > 0) 
	{
		result = true;
	}
	else 
	{
		result = false;
	}

	return result;
}

// < 运算符重载
bool String::operator < (const String &str)
{
	bool result = true;
	if(strcmp(this->mString, str.mString) < 0) 
	{
		result = true;
	}
	else 
	{
		result = false;
	}

	return result;
}

//[] 运算符重载
char &String::operator [](const int &index)
{
	return this->mString[index];
}

//析构
String::~String()
{
	delete [] mString;
	std::cout << "析构函数" << std::endl;
}

//打印
void String::Show()
{
	std::cout << "string: " << mString << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "str:" << std::endl;
	String str("aaaaa"); //构造函数
	std::cout << "str2:" << std::endl;
	String str2(str);    //拷贝构造函数
	str.Show();          //aaaaa
	str2.Show(); 		 //aaaaa

	std::cout << "str3:" << std::endl;
	String str3 = str;   //=运算符重载--拷贝构造函数
	str3.Show();         //aaaaa

	if(str3 == str2)     //==运算符重载
	{
		std::cout << "str3 == str2" << std::endl;
	}

	std::cout << "str4:" << std::endl;
	//验证关系运算符
	String str4 = "abcdefg";
	String str5 = "abcdef";
	if(str4 > str5)
	{
		std::cout << "str4 > str5" << std::endl;
	}
	if(str5 < str4)
	{
		std::cout << "str5 < str4" << std::endl;
	}

	std::cout << "str4 + str5 :" << std::endl;
	String str6 = str4 + str5;
	str6.Show();
	return 0;
}
