vector<int> prime(1001, 1);

for (int i = 2; i * i < 1001; i++)
{
    if (prime[i] == 1)
    {
        for (int j = i * i; j <= 1000; j += i)
        {
            prime[j] = 0;
        }
    }
}

vector<int> res;
for (int i = 2; i < 1001; i++)
{
    if (prime[i] == 1)
    {
        res.push_back(i);
    }
}