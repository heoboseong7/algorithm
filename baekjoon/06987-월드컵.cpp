#include <bits/stdc++.h>

using namespace std;
//0 win 1 draw 2 lose
int result[6][3];
int input[4][6][3];
int ans[4];
pair<int, int> match[15];

void rec(int cnt)
{
    if (cnt == 15)
    {
        for (int i = 0; i < 4; i++)
        {
            bool possible = true;
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (result[j][k] != input[i][j][k])
                        possible = false;
                }
            }
            if (possible)
                ans[i] = 1;
        }
        return;
    }
    int i = match[cnt].first;
    int j = match[cnt].second;
    // 승-패
    result[i][0]++;
    result[j][2]++;
    rec(cnt + 1);
    result[i][0]--;
    result[j][2]--;
    // 무승부
    result[i][1]++;
    result[j][1]++;
    rec(cnt + 1);
    result[i][1]--;
    result[j][1]--;
    //패-승
    result[i][2]++;
    result[j][0]++;
    rec(cnt + 1);
    result[i][2]--;
    result[j][0]--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 3; k++)
                cin >> input[i][j][k];
    //n번째 게임에 해당하는 두 팀
    int idx = 0;
    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            match[idx++] = make_pair(i, j);

    rec(0);

    for (int i = 0; i < 4; i++)
        cout << ans[i] << ' ';

    return 0;
}