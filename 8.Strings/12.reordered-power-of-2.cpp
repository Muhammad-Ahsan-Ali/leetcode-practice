class Solution
{
private:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && !(n & (n - 1));
    }

public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        int size = s.length();

        auto util = [&](auto &&util, int ind) -> bool
        {
            if (ind == size)
            {
                if (s[0] != '0' && isPowerOfTwo(stoi(s)))
                {
                    return true;
                }
                return false;
            }

            unordered_set<char> used;
            for (int i = ind; i < size; ++i)
            {
                if (used.count(s[i]))
                    continue;
                used.insert(s[i]);
                swap(s[i], s[ind]);
                if (util(util, ind + 1))
                    return true;
                swap(s[i], s[ind]);
            }
            return false;
        };

        return util(util, 0);
    }
};

// optimized

class Solution
{
private:
    bool computed = false;
    unordered_set<string> st;

public:
    bool reorderedPowerOf2(int n)
    {

        if (!computed)
        {
            for (int i = 0; i < 31; i++)
            {
                long long val = 1 << i;
                string temp = to_string(val);
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }

        string temp = to_string(n);
        sort(temp.begin(), temp.end());
        return st.contains(temp);
    }
};

