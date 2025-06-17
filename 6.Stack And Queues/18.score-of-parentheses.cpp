class Solution
{
public:
    int scoreOfParentheses(string s)
    {

        stack<int> st;

        for (auto &c : s)
        {
            if (c == '(')
                st.push(0);
            else
            {
                int val = 0;
                while (st.top() != 0)
                {
                    val += st.top();
                    st.pop();
                }
                val = max(2 * val, 1);
                st.pop();
                st.push(val);
            }
        }

        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// OPTIMIZED

class Solution
{
public:
    int scoreOfParentheses(string s)
    {

        int depth = 0;
        int ans = 0;
        char prev = '(';
        for (auto &c : s)
        {
            if (c == '(')
                depth++;
            else
            {
                depth--;
                if (prev == '(')
                    ans += pow(2, depth);
            }
            prev = c;
        }

        return ans;
    }
};