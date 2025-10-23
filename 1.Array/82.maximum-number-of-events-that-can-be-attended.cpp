class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int n = events.size();

        sort(events.begin(), events.end(), [&](vector<int> &a, vector<int> &b)
             { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });

        priority_queue<int, vector<int>, greater<int>> pq;

        int res = 0;
        int i = 0;
        int day = 0;

        while (i < n || !pq.empty())
        {
            if (pq.empty())
                day = max(day, events[i][0]);

            while (i < n && events[i][0] <= day)
                pq.push(events[i][1]), i++;

            pq.pop();
            day++;
            res++;

            while (!pq.empty() && pq.top() < day)
                pq.pop();
        }

        return res;
    }
};
