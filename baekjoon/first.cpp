#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MAXN 200005

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> timein(n, 0);
	vector<int> timeend(n);
	vector<int> judge(n, 0);
	for (int i = 0; i < n; i++)
	{
		vector<int> jdend(k, 0);
		for (int j = 0; j < i; j++)
		{
			jdend[judge[j]] = timeend[j];
		}
		int jd = 0;
		int tm = 1000000;
		for (int j = 0; j < k; j++)
		{
			if (jdend[j] < tm)
			{
				tm = jdend[j];
				jd = j;
			}
		}
		timein[i] = tm;
		judge[i] = jd;
		timeend[i] = tm + arr[i];
	}
	vector<int> timing(150 * 2000, 0);
	vector<int> copy;
	copy = timeend;
	sort(copy.begin(), copy.end());
	for (int i = 0; i < n; i++)
	{
		timing[copy[i]] = i + 1;
	}
	for (int i = 1; i < 150 * 2000; i++)
		timing[i] = max(timing[i], timing[i - 1]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int tm = timein[i];
		int pp = 0;
		for (int j = 0; j < arr[i]; j++)
		{
			int d = (int)(((double)timing[j + tm] / (double)(n)) * 100.0 + 0.5);
			if (d == (j + 1))
				pp = 1;
		}
		ans += pp;
	}
	cout << ans << endl;
	return 0;
}
