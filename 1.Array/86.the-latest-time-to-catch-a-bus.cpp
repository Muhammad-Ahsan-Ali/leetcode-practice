class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int m = passengers.size();
        int p = 0;

        int lastBoardedOnLastBus = -1;
        int lastCountOnLastBus = 0;

        for (int i = 0; i < buses.size(); ++i)
        {
            int bus = buses[i];
            int count = 0;
            while (p < m && passengers[p] <= bus && count < capacity)
            {
                if (i == buses.size() - 1)
                    lastBoardedOnLastBus = passengers[p];
                ++p;
                ++count;
            }
            if (i == buses.size() - 1)
                lastCountOnLastBus = count;
        }

        int candidate;
        if (lastCountOnLastBus < capacity)
            candidate = buses.back();
        else
            candidate = lastBoardedOnLastBus - 1;

        int idx = upper_bound(passengers.begin(), passengers.end(), candidate) - passengers.begin() - 1;
        while (idx >= 0 && passengers[idx] == candidate)
        {
            --candidate;
            --idx;
        }
        return candidate;
    }
};
