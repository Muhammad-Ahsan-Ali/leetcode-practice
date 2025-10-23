class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;

        int n = pushed.size();

        int ind = 0;

        for (int i = 0; i < n; i++)
        {
            int cur = popped[i];

            while (true)
            {
                if (!s.empty() && s.top() == cur)
                {
                    s.pop();
                    break;
                }
                else
                {
                    if (ind < n)
                        s.push(pushed[ind++]);
                    else
                        return false;
                }
            }
        }

        return true;
    }
};

// chat gpt sol

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int j = 0;

        for (int val : pushed)
        {
            s.push(val);
            // Pop from the stack while the top matches the next popped value
            while (!s.empty() && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};
