#include <iostream>
#include <cstdio>
using namespace std;
void SwapVariable(int &temp_a, int &temp_b);
void SwapVariable(double &temp_a, double &temp_b);

int main()
{
    int a = 10;
    int b = 20;
    cout << "a = " << a << " b = " << b << endl;
    SwapVariable(a, b);
    cout << "a = " << a << " b = " << b << endl;

    double c = 10;
    double d = 20;
    cout << "c = " << c << " d = " << d << endl;
    SwapVariable(c, d);
    cout << "c = " << c << " d = " << d << endl;
    return 0;
}

void SwapVariable(int &temp_a, int &temp_b)
{
    int temp;
    temp = temp_a;
    temp_a = temp_b;
    temp_b = temp;
}

void SwapVariable(double &temp_a, double &temp_b)
{
    double temp;
    temp = temp_a;
    temp_a = temp_b;
    temp_b = temp;
}