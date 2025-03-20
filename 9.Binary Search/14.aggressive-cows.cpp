
class Solution
{
private:
    bool isPossible(vector<int> &stalls, int dist, int cows)
    {
        int last = stalls[0];
        int cows_placed = 1;
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= dist)
            {
                last = stalls[i];
                cows_placed++;
            }
            if (cows_placed >= cows)
            {
                return true;
            }
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[stalls.size() - 1] - stalls[0];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(stalls, mid, k))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};