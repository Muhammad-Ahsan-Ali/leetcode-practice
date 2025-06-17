string toBaseB(string num, int b)
{

    if (num == "0")
        return "0";

    string res = "";

    while (num != "")
    {
        string next = "";
        int rem = 0;
        for (int i = 0; i < num.length(); i++)
        {
            int cur = rem * 10 + (num[i] - '0');
            int div = cur / b;
            rem = cur % b;

            if (!next.empty() || div != 0)
                next += (div + '0');
        }
        res = char(rem + '0') + res;
        num = next;
    }

    return res;
}
