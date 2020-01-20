#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	const char *mbString = "多字节字符串到宽字符串的转换";

	cout << "const char * = " << mbString << endl;

	size_t requiredSize = mbstowcs(nullptr, mbString, 0);
	wchar_t *wcString = new wchar_t[requiredSize + 1];
	if (static_cast<size_t>(-1) == mbstowcs(wcString, mbString, requiredSize + 1))
	{
		cout << "Couldn't convert string: invalid multibyte character." << endl;
	}
	else
	{
		cout << "wchar_t * = " << wcString << endl;
		//wcout << "wchar_t * = " << wcString << endl;
	}
	delete[] wcString;
	return 0;
}
