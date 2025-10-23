class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<string> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < logs.size(); i++)
        {
            string log = logs[i];
            int p1 = log.find(':') + 1;

            if (logs[i][p1] == 's')
            {
                st.push(logs[i]);
            }
            else
            {
                int p2 = log.rfind(':') + 1;
                int end = stoi(logs[i].substr(p2));
                int used = 0;

                while (st.top()[0] == 'c')
                {
                    used += stoi(st.top().substr(2));
                    st.pop();
                }
                int strtP = st.top().rfind(':') + 1;
                int start = stoi(st.top().substr(strtP));
                st.pop();
                int time = end - start - used + 1;
                used += time;
                ans[stoi(logs[i].substr(0, logs[i].find(':')))] += time;
                if (!st.empty())
                    st.push("c:" + to_string(used));
            }
        }
        return ans;
    }
};

// optimized

class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<int> st;
        vector<int> ans(n, 0);

        int prevTime = 0;

        for (int i = 0; i < logs.size(); i++)
        {
            string log = logs[i];
            int p1 = log.find(':') + 1;
            int id = stoi(log.substr(0, p1));
            int p2 = log.rfind(':') + 1;
            int time = stoi(log.substr(p2));
            if (logs[i][p1] == 's')
            {
                if (!st.empty())
                    ans[st.top()] += time - prevTime;
                st.push(id);
                prevTime = time;
            }
            else
            {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};