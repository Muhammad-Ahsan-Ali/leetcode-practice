#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{

    // Counting Sort Algo..................

    // int maxNum = nums[0];
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     maxNum = max(maxNum, nums[i]);
    // }

    // std::vector<int> countArray(maxNum + 1, 0);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     countArray[nums[i]]++;
    // }

    // for (int i = 1; i < countArray.size(); i++)
    // {
    //     countArray[i] += countArray[i - 1];
    // }

    // vector<int> sortedArray(nums.size());

    // for (int i = nums.size() - 1; i >= 0; i--)
    // {
    //     sortedArray[countArray[nums[i]] - 1] = nums[i];
    //     countArray[nums[i]]--;
    // }
    // nums = sortedArray;

    // DNF Algo......................................

    int low = 0;
    int high = nums.size() - 1;

    for (int i = 0; i <= high; i++)
    {
        if (nums[i] == 0)
        {
            swap(nums[low], nums[i]);
            low++;
        }
        if (nums[i] == 2)
        {
            swap(nums[high], nums[i]);
            i--;
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 0};

    sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ",";
    }
    return 0;
}