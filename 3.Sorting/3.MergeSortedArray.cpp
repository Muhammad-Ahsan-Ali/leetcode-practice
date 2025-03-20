#include <iostream>
#include <vector>

using namespace std;

void swapGreater(vector<int> &num1, vector<int> &num2, int index1, int index2)
{
    if (num1[index1] > num2[index2])
    {
        swap(num1[index1], num2[index2]);
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int gap = ((m + n) / 2) + ((m + n) % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < (m + n))
        {

            // if in 1st part

            if (right < m && left < m)
            {
                swapGreater(nums1, nums1, left, right);
            }

            // if in 2nd part

            else if (right >= m && left >= m)
            {
                swapGreater(nums2, nums2, left - m, right - m);
            }

            // if lest in 1st and right in second part
            else
            {
                swapGreater(nums1, nums2, left, right - m);
            }
            left++;
            right++;
        }

        if (gap == 1)
        {
            break;
        }

        gap = ((gap) / 2) + ((gap) % 2);
    }
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
}

int main()
{

    vector<int> num1 = {1, 2, 3};
    vector<int> num2 = {2, 5, 6};
    int len1 = num1.size();
    int len2 = num1.size();

    merge(num1, len1, num2, len2);

    for (int i = 0; i < (len1 + len2); i++)
    {
        cout << num1[i];
    }

    return 0;
}


// optimized

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int a = m - 1;
        int b = n - 1;
        int c = m + n - 1;

        while (b >= 0)
        {
            if (a >= 0 && nums1[a] > nums2[b])
            {
                nums1[c] = nums1[a];
                a--;
            }
            else
            {
                nums1[c] = nums2[b];
                b--;
            }
            c--;
        }
    }
};
