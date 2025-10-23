class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                cnt++;
                if (cnt > 1)
                    return 0;

                if (i - 2 < 0 || nums[i - 2] <= nums[i]) // case( /\ ) ===dec top==> ( ____ )
                    nums[i - 1] = nums[i];
                else // case( ‾‾‾‾‾\ ) ===incre end==> ( ‾‾‾‾‾‾ )
                    nums[i] = nums[i - 1];
            }
        }
        return 1;
    }
};
