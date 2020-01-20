#include <iostream>
#include <string>
#include <cstdlib>

//std::string->const char *
void StringToConstChar(std::string str, const char *ch)
{
	ch = str.c_str();
}

//std::string->char *
void StringToChar(std::string str, char *ch)
{
	int len = str.length();
	ch = (char *)malloc((len + 1) * sizeof(char));
	if(!ch)
	{
		return ;
	}
	str.copy(ch, len, 0);
}

//std::string->char []
void StringToCharArray(std::string str, char ch[])
{

}


int main(int argc, char *argv[])
{
	std::string str = std::string("hello world");
	const char *ch1 ;
	const char *ch2;
	char *ch3;
	//std::string to char *
	//1.c_str()---只可转换为const char *
	ch1 = str.c_str();
	std::cout << "std::string = " << str << std::endl;
	std::cout << "after c_str() char1 = " << ch1 << std::endl;
	//2.data()---只可转换为const char *
	ch2 = str.data();
	std::cout << "std::string = " << str << std::endl;
	std::cout << "after data() char2 * = " << ch2 << std::endl;
	//3.copy()---可通过malloc实现到char *的转换
	int len = str.length();
	ch3 = (char *)malloc((len + 1) * sizeof(char));
	str.copy(ch3, len, 0);
	std::cout << "std::string = " << str << "  length = " << len << std::endl;
	std::cout << "after copy() char3 * = " << ch3 << std::endl;
	//4.copy()---std::string -> char []
	char data[12];
	str.copy(data, len, 0);
	std::cout << "std::string = " << str << "  length = " << len << std::endl;
	std::cout << "after copy() char data[12] = " << data << std::endl;

	//5. char * --> std::string
	//直接赋值

	return 0;
}

