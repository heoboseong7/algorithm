#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<int>> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
int N, input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> input;
		if(maxheap.size() == minheap.size()) maxheap.push(input);
		else minheap.push(input);
		
		if(!minheap.empty() && !maxheap.empty() && maxheap.top() > minheap.top()) {
			int a = maxheap.top(), b = minheap.top();
			maxheap.pop(); minheap.pop();
			maxheap.push(b); minheap.push(a);
		}
		cout << maxheap.top() << '\n';
	}
	
	return 0;
}