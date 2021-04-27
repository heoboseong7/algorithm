#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for (int var = start; var < to; var++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) ((a < 0) ? -a : a)
#define fi first
#define se second
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m;
map<char, double> preference;
string status[101];
string genre[101];
bool check[101][11];

class Content
{
public:
    char status;
    char genre;
    int x;
    int y;
    Content(char status, char genre, int x, int y) : status(status), genre(genre), x(x), y(y) {}
};

vector<Content> contents;

bool cmp(Content a, Content b)
{
    // O < W < W
    if (a.status != b.status)
        return (a.status > b.status);
    else
    {
        if (preference[a.genre] != preference[b.genre])
            return preference[a.genre] > preference[b.genre];
        else
        {
            return a.x * m + a.y < b.x * m + b.y;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);

    for (int i = 0; i < 5; i++)
    {
        double input;
        cin >> input;
        preference['A' + i] = input;
    }
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> status[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> genre[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            contents.push_back(Content(status[i][j], genre[i][j], i, j));
        }
    }
    sort(contents.begin(), contents.end(), cmp);

    int c_size = contents.size();
    for (int i = 0; i < c_size; i++)
    {
        if (contents[i].status == 'W')
            continue;
        cout << contents[i].genre << ' ' << preference[contents[i].genre] << ' ' << contents[i].x << ' ' << contents[i].y << '\n';
    }
    return 0;
}
