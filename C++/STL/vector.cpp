#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

	vector<int> v1;
	//vector的容量会自动增大,可能是以2的倍数增加,如1, 2, 4, 8, ...(当存储不足时自动增大,直至max_size())
	for(int i = 0; i < 100 ; i ++) {
		v1.push_back(i);
		cout << "第" << i+1 << "次" <<  ", capacity  = " << v1.capacity() << endl;
	}

	cout << "vector max_size() = " << v1.max_size() << endl;
	cout << "finally capacity = " << v1.capacity() << endl;

#if 0
Vector的容量之所以重要，有以下两个原因：
	1. 容器的大小一旦超过capacity的大小，vector会重新配置内部的存储器，导致和vector元素相关的所有reference、pointers、iterator都会失效。
	2.内存的重新配置会很耗时间。
#endif

	//避免容器重新分配内存的方法--Reserve()保留适当容量
	//创建容器一开始即reserve(int len)适当的容量,len对于实际问题足够大
	vector <int> v2;
	v2.reserve(3); //为v2分配容量为3
	cout << "v2.capacity() = " << v2.capacity() << endl;

	//避免容器重新分配内存的方法--创建容器时，利用构造函数初始化的出足够的空间
	vector <int > v3(3); //为v3分配容量为3
	cout << "v3.capacity() = " << v3.capacity() << endl;

	return 0;
}
