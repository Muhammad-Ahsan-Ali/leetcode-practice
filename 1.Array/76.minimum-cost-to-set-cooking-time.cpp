class Solution
{
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost,
                       int targetSeconds)
    {

        function<int(int, int)> cal = [&](int min, int sec) -> int
        {
            int tar = (min * 100) + sec;
            vector<int> v;
            while (tar)
                v.push_back(tar % 10), tar /= 10;

            reverse(v.begin(), v.end());

            int strt = startAt;
            int cost = 0;
            for (auto dig : v)
            {
                cost += pushCost;
                if (dig != strt)
                    cost += moveCost;
                strt = dig;
            }
            return cost;
        };

        int ans = INT_MAX;
        if (targetSeconds >= 100)
        {
            int minu = targetSeconds / 60;
            int sec = targetSeconds % 60;
            if (minu < 100)
                ans = min(ans, cal(minu, sec));
            minu--;
            sec += 60;
            if (sec <= 99)
                ans = min(ans, cal(minu, sec));
        }
        else
        {
            ans = min(ans, cal(0, targetSeconds));
            if (targetSeconds >= 60)
                ans = min(ans, cal(1, targetSeconds % 60));
        }
        return ans;
    }
};