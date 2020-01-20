#include <iostream>
#include <hash_map>

int main()
{
	std::hash_map<int, std::string> mhash;
	mhash[1001] = "hello";
	mhash[1002] = "world";

	for( auto it = mhash.begin(); it != mhash.end(); it ++)
	{
		std::cout << it->first << "---" << it->second << std::endl;
	}
	return 0;
}
