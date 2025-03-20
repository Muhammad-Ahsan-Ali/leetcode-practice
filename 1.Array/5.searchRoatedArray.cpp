#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int search(int array[], int length, int traget)
{
    int k = length;
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            k = i;
        }
    }
    if (traget < array[k] && traget > array[0])
    {
        int right = k;
        int left = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (array[mid] == traget)
            {
                return mid;
            }
            if (array[mid] > traget)
            {
                right = mid - 1;
            }
            if (array[mid] < traget)
            {
                left = mid + 1;
            }
        }
    }
    else
    {
        int left = k + 1;
        int right = length;
        cout << left << " ";
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (array[mid] == traget)
            {
                return mid;
            }
            if (array[mid] > traget)
            {
                right = mid - 1;
            }
            if (array[mid] < traget)
            {
                left = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{

    int array[] = {4, 5, 6, 7, 0, 1, 2};
    // int array[] = {0, 1, 2, 4, 5, 6, 7};
    int length = sizeof(array) / sizeof(array[0]);
    cout << search(array, length, 0);

    return 0;
}

// optimized

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (high + low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};