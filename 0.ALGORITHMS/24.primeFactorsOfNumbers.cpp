vector<vector<int>> pfac(1e5 + 1);

void getPf
{
    for (int i = 2; i <= 1e5; i++)
    {
        if (!pfac[i].empty())
            continue;

        for (int j = i; j <= N; j += i)
            pfac[j].push_back(i);
    }
}