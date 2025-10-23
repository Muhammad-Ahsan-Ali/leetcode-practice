class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int idx = 0;
        int i = 0;

        while (i < n)
        {
            char curr_char = chars[i];
            int cnt = 0;
            while (i < n && chars[i] == curr_char)
            {
                cnt++;
                i++;
            }

            chars[idx++] = curr_char;
            if (cnt > 1)
            {
                string str_cnt = to_string(cnt);
                for (auto c : str_cnt)
                    chars[idx++] = c;
            }
        }

        return idx;
    }
};