#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    int pos = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r)
        {
            if ((nums[i] + nums[l] + nums[r]) == 0)
            {
                vector<int> threeSum;
                threeSum.push_back(nums[i]);
                threeSum.push_back(nums[l]);
                threeSum.push_back(nums[r]);
                result.push_back(threeSum);

                while (l < r && nums[l] == nums[l + 1])
                    l++;
                while (l < r && nums[r] == nums[r - 1])
                    r--;

                l++;
                r--;
            }
            else if ((nums[i] + nums[l] + nums[r]) < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> array = {-1, 0, 1, 2, -1, -4};
    threeSum(array);
    return 0;
}