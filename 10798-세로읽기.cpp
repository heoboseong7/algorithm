#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char word[5][16] = { 0, };

int main() {
	for (int i = 0; i < 5; i++)
		scanf("%s", word[i]);

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 5; j++)
			if (word[j][i] != 0)
				cout << word[j][i];

	return 0;
}
