class Solution
{
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        vector<int> temp;
        int right = mid + 1;
        int left = low;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                cnt += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {

            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
        {
            return cnt;
        }
        int mid = (high + low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int localInv = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                localInv++;
            }
        }
        int globalInv = mergeSort(nums, 0, n - 1);
        return localInv == globalInv;
    }
};

// optimized

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int maxi = -1;

        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            maxi = max(nums[i], maxi);
            if (maxi > nums[i + 2])
            {
                return false;
            }
        }
        return true;
    }
};