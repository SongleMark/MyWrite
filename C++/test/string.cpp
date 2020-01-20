#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class String {
public:
	String(const char *str = nullptr);
	String(const String &str);
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
}

String::String(const String &str) {
	int len = strlen(str.mStr);
	mStr = new char[len + 1];
	strncpy(mStr, str.mStr, len);
	mStr[len] = '\0';
}

String::~String() {
	delete mStr;
	mStr = nullptr;
}

void String::Show() {
	std::cout << "string = " << mStr << std::endl;
}

int main(int argc, char *argv[]) {
	String str("hello, world !!!");
	str.Show();
	String str1 = str;
	str1.Show();

	return 0;
}


