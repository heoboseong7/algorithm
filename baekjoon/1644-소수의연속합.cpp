#include <bits/stdc++.h>

using namespace std;

bool *primearray;
vector<int> primes;

void setprimearray(int N)
{
    delete primearray;
    primearray = new bool[N + 1];
    for (int i = 2; i <= N; i++)
        primearray[i] = true;
}

void Eratos(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (primearray[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                primearray[j] = false;
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    setprimearray(n);
    Eratos(n);
    for (int i = 2; i <= n; i++)
    {
        if (primearray[i])
        {
            primes.push_back(i);
        }
    }
    int front = 0, end = 1, ans = 0;
    int sum = primes[0];
    int n_prime = (int)primes.size();
    while (front <= end && end <= n_prime && front < n_prime)
    {
        if (n == sum)
        {
            sum -= primes[front++];
            ans++;
        }
        else if (n < sum)
        {
            sum -= primes[front++];
        }
        else
        {
            if (end < n_prime)
                sum += primes[end];
            end++;
        }
    }
    cout << ans;

    delete primearray;
    return 0;
}
