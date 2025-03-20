class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {

        vector<pair<int, int>> meetings;

        int n = start.size();

        for (int i = 0; i < n; i++)
        {
            meetings.push_back({start[i], end[i]});
        }

        sort(meetings.begin(), meetings.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        int res = 0;
        int lastFinishTime = -1;

        for (int i = 0; i < n; i++)
        {
            if (lastFinishTime < meetings[i].first)
            {
                res++;
                lastFinishTime = meetings[i].second;
            }
        }

        return res;
    }
};