#include <iostream>

using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int gcd2(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * (b / gcd(a, b));
}

int main()
{
	cout << gcd(-3, 6);
}
