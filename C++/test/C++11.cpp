#include <iostream>
#include <thread>
#include <list>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

void hello()
{
	time_t td;
	//tm *curent_time;
	while(1)
	{
		td = time(NULL);
		tm *current_time = localtime(&td);

		std::cout << current_time->tm_year + 1900 << "年" << current_time->tm_mon + 1 << "月" << current_time->tm_mday << "日" 
			<< current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec << std::endl;
		sleep(1);
	}

	//std::cout << "thread::hello" << std::endl;
}

/*
 * c++11拖尾返回类型，若编译条件为C++14则不需写->decltype(a+b)
 ************************************************************/
template <typename A = int, typename B = int>
auto AddFunc(A a, B b)->decltype(a + b)
{
	return a + b;
}

int main()
{
	std::thread t(hello);
	t.join();
	std::cout << "main::hello" << std::endl;
	std::list <int > a;
	a.push_back(8);
	a.push_back(9);

	for(auto it = a.begin(); it != a.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "Add(5 + 6.8) = " << AddFunc(5, 6.8) << std::endl;
	return 0;
}
