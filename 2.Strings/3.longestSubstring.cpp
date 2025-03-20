 
int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    int maxLen = 0;
    int start = 0;

    vector<int> hash(256, -1);

    for (int i = 0; i < len; i++)
    {
        if (hash[s[i]] >= start)
        {
            start = hash[s[i]] + 1;
        }

        hash[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }

    return maxLen;
}
 