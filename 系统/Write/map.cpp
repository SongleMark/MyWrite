#include <iostream>
#include <map>
#include <list>
#include <string>

int main()
{
	std::map<int, std::string> Map;

	std::list<std::string> List;
	//List.append("one");
	//List.insert("two");
	//List.append("three");
	List.push_back("q");
	List.push_back("w");
	Map.insert(std::pair<int, std::string>(1, "b"));
	Map.insert(std::pair<int, std::string>(2, "a"));

	for(auto it = Map.begin(); it != Map.end(); it ++)
	{
		std::cout << it->first << "---" << it->second << std::endl ;
	}
	std::cout << std::endl;
	return 0;
}
