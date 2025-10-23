
// Bits
string decToBinary(ll n)
{
    string s = "";
    ll i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}

//
ll binaryToDecimal(string n)
{
    string num = n;
    ll ans = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            ans += base;
        base = base * 2;
    }
    return ans;
}
