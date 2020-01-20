#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "../headers/menu.h"
using namespace std;

int main(int argc,char **argv)
{
	system("clear");
	cout << MAINMENU ;
	int sel;
	cin >> sel;
	return 0;
}
