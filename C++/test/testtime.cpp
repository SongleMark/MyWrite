#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char str[128];
	time_t now_time;
	now_time = time(NULL);
	tm *currenttime = localtime(&now_time);
	cout << asctime(currenttime) << endl;

	//strftime(str, 128, "%Y-%h-%d-%T", currenttime);
	strftime(str, 128, "%F-%T", currenttime);
	//std::cout << "\e[031m";//red
	//std::cout << "\e[032m";//浅绿色
	std::cout << "\e[033m";
	cout << str << endl;
	std::cout << "\e[0m" ;
	//cout << system("time") << endl;;
	return 0;
}

