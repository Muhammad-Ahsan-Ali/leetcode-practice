#include <iostream>
using namespace std;

int minimumDeletions(int array[], int array_length)
{
    int cost[3] = {0, 0, 0};
    int minimum = array[1];
    int maximum = array[1];
    int minimumDeletions = array_length;

    for (int i = 0; i < array_length; i++)
    {
        if (minimum > array[i])
        {
            minimum = array[i];
        }
        if (maximum < array[i])
        {
            maximum = array[i];
        }
    }

    int min_flag = 0;
    int max_flag = 0;

    for (int i = 0; i < array_length; i++)
    {

        if (min_flag == 0 || max_flag == 0)
        {
            cost[0]++;
        }

        if ((min_flag == 0) && (max_flag == 0))
        {
            cost[2]++;
        }

        if (array[i] == minimum)
        {
            min_flag = 1;
        }
        if (array[i] == maximum)
        {
            max_flag = 1;
        }
    }

    min_flag = 0;
    max_flag = 0;

    for (int i = array_length - 1; i >= 0; i--)
    {

        if (min_flag == 0 || max_flag == 0)
        {
            cost[1]++;
        }

        if (min_flag == 0 && max_flag == 0)
        {
            cost[2]++;
        }

        if (array[i] == minimum)
        {
            min_flag = 1;
        }
        if (array[i] == maximum)
        {
            max_flag = 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (minimumDeletions > cost[i])
        {
            minimumDeletions = cost[i];
        }
    }

    return minimumDeletions;
}

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        pair<int, int> high = {INT_MIN, 0};
        pair<int, int> low = {INT_MAX, 0};

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > high.first)
                high = {nums[i], i};
            if (nums[i] < low.first)
                low = {nums[i], i};
        }

        int highindex = high.second, lowindex = low.second;
        if (highindex < lowindex)
            swap(highindex, lowindex);

        int option1 = highindex + 1;
        int option2 = n - lowindex;
        int option3 = (lowindex + 1) + (n - highindex);

        return min({option1, option2, option3});
    }
};

int main()
{

    int array[6] = {3, 7, 21, 9, 0, 12};
    int array_length = sizeof(array) / sizeof(array[0]);
    int miminum = minimumDeletions(array, array_length);
    cout << endl
         << miminum << endl
         << endl;

    return 0;
}