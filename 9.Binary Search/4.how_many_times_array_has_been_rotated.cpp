class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {

        int n = arr.size();
        int mini = INT_MAX;
        int mini_ind = 0;

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (high + low) / 2;

            if (arr[low] <= arr[mid])
            {
                if (mini < arr[low])
                {
                    mini = arr[low];
                    int mini_ind = low;
                }

                low = mid + 1;
            }
            else
            {
                if (mini < arr[mid])
                {
                    mini = arr[mid];
                    int mini_ind = mid;
                }
                high = mid - 1;
            }
        }

        return mini_ind;
    }
};
