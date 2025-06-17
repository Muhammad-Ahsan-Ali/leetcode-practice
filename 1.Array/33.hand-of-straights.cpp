class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return false;

        map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[hand[i]]++;

        while (!mp.empty())
        {
            int cur = mp.begin()->first;

            for (int i = 0; i < groupSize; i++)
            {
                if (!mp.contains(cur + i))
                    return false;
                mp[cur + i]--;
                if (mp[cur + i] < 1)
                    mp.erase(cur + i);
            }
        }

        return true;
    }
};