class Solution
{
private:
    using pi = pair<int, int>;
    using ti = tuple<long long, int, int>;

public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        priority_queue<pi, vector<pi>, greater<pi>> availSrvrs; // (weight, index)
        priority_queue<ti, vector<ti>, greater<ti>> busySrvrs;  // (releaseTime, weight, index)
        int n = tasks.size();
        vector<int> ans;

        for (int i = 0; i < servers.size(); i++)
            availSrvrs.push({servers[i], i});

        long long curTime = 0;

        for (int i = 0; i < n; i++)
        {
            int t = tasks[i];
            curTime = max(curTime, (long long)i);
            if (availSrvrs.empty())
                curTime = get<0>(busySrvrs.top());

            while (!busySrvrs.empty() && get<0>(busySrvrs.top()) <= curTime)
            {
                auto [tst, srvr, idx] = busySrvrs.top();
                busySrvrs.pop();
                availSrvrs.push({srvr, idx});
            }

            auto [srvr, idx] = availSrvrs.top();
            ans.push_back(idx);
            availSrvrs.pop();
            busySrvrs.push({t + curTime, srvr, idx});
        }
        return ans;
    }
};