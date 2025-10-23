class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;

        while (k--)
        {
            if (l < 0)
                r++;
            else if (r >= n)
                l--;
            else if (x - arr[l] <= arr[r] - x)
                l--;
            else
                r++;
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};
