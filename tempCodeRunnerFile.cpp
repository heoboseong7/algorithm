f (v.size() == 3)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / m, y = v[i] % m;
            lab[x][y] = 1;
        }
        ans = max(ans, test());
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / m, y = v[i] % m;
            lab[x][y] = 0;
        }
        return;
    }