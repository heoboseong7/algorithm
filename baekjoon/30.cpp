#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

int main()
{
	char number[100001];
	cin >> number;
	int n = strlen(number);
	int TF = 0;
	for (int i = 0; i < n; i++)
		TF += number[i] - 48;

	sort(number, number + n, greater<int>());

	if (TF > 0 && (TF % 3 == 0))
	{
		if (number[n - 1] != '0')
		{
			cout << "-1";
			return 0;
		}
		else
		{
			for (int i = 0; i < n; i++)
				cout << number[i];
		}
	}
	else
		cout << "-1";

	return 0;
}
