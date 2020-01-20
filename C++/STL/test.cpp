#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int > v1;
	for(int i = 0 ; i < 10 ; i ++) {
		cout << "when time = " << i + 1 << ", capacity = " << v1.capacity() << ", v.size() = " << v1.size() 
			 << ", v.max_size() = " <<  v1.max_size() << endl;
		v1.push_back(i);
	}

	//cout << "end capacity = " << v1.capacity() << endl;
	cout << "end time capacity = " << v1.capacity() << ", v.size() = " << v1.size() 
		 << ", v.max_size() = " <<  v1.max_size() << endl;

	vector<int> v2;
	//v2.resize(15);
	v2.reserve(10);
	for(int i = 0 ; i < 10 ; i ++) {
		v2.push_back(i);
		cout << "v2.capacity() = " << v2.capacity() << endl;
	}


	return 0;
}
