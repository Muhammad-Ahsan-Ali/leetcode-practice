class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        int cnt = 0;
        int track = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                track++;
            }
            else
            {
                track--;
            }
            if (track < 0)
            {
                cnt++;
                track = 0;
            }
        }
        return cnt + track;
    }
};