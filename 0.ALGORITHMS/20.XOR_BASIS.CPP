int basis[31];

void insert(int num)
{

    for (int i = 30; i >= 0; i--)
    {
        if (!(num & (1 << i)))
            continue;

        if (!basis[i])
        {
            basis[i] = num;
            return;
        }

        num ^= basis[i];
    }
}
int getMax()
{
    int ans = 0;
    for (int i = 30; i >= 0; i--)
        ans = max(ans, ans ^ basis[i]);
    return ans;
}
