#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int **nums, int lenNums)
{
    int maxNum = nums[0][0];
    for (int i = 0; i < lenNums; i++)
    {
        maxNum = max(maxNum, nums[i][0]);
    }

    int *countArray = new int[maxNum + 1](); // Dynamically allocate and initialize

    for (int i = 0; i < lenNums; i++)
    {
        countArray[nums[i][0]]++;
    }

    for (int i = 1; i <= maxNum; i++)
    {
        countArray[i] += countArray[i - 1];
    }

    int **sortedArray = new int *[lenNums];
    for (int i = 0; i < lenNums; i++)
    {
        sortedArray[i] = new int[2];
    }

    for (int i = lenNums - 1; i >= 0; i--)
    {
        sortedArray[countArray[nums[i][0]] - 1][0] = nums[i][0];
        sortedArray[countArray[nums[i][0]] - 1][1] = nums[i][1];
        countArray[nums[i][0]]--;
    }

    for (int i = 0; i < lenNums; i++)
    {
        nums[i][0] = sortedArray[i][0];
        nums[i][1] = sortedArray[i][1];
    }

    for (int i = 0; i < lenNums; i++)
    {
        delete[] sortedArray[i];
    }
    delete[] sortedArray;
    delete[] countArray; // Clean up memory for countArray
}

int **merge(int **&intervals, int &len)
{
    countingSort(intervals, len);

    for (int i = 0; i < len - 1;)
    { // Changed to avoid skipping after removal
        int minI = intervals[i][0];
        int maxI = intervals[i][1];

        if (intervals[i][1] >= intervals[i + 1][0])
        {
            if (intervals[i][1] > maxI)
            {
                maxI = intervals[i][1];
            }

            if (intervals[i + 1][0] > maxI)
            {
                maxI = intervals[i + 1][0];
            }

            if (intervals[i + 1][1] > maxI)
            {
                maxI = intervals[i + 1][1];
            }

            if (intervals[i][1] < minI)
            {
                minI = intervals[i][1];
            }

            if (intervals[i + 1][0] < minI)
            {
                minI = intervals[i + 1][0];
            }

            if (intervals[i + 1][1] < minI)
            {
                minI = intervals[i + 1][1];
            }

            // Create a new merged interval
            int *temp = new int[2]{minI, maxI};
            for (int j = i + 1; j < len; j++)
            {
                intervals[j - 1] = intervals[j];
            }
            intervals[i] = temp;
            len--;
        }
        else
        {
            i++; // Move to the next interval only if no merge occurred
        }
    }
    return intervals;
}

int main()
{
    int rows = 2;
    int cols = 2;

    // Dynamically allocate memory for a 2D array using pointers
    int **array = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }

    // Assign values to the 2D array
    array[0][0] = 1;
    array[0][1] = 3;
    array[1][0] = 2;
    array[1][1] = 6;

    int len = rows; // Set the length to the number of rows

    // Merge intervals
    merge(array, len);

    // Output merged intervals
    for (int i = 0; i < len; i++)
    {
        cout << "{";
        for (int j = 0; j < 2; j++)
        {
            cout << array[i][j] << (j == 1 ? "" : ",");
        }
        cout << "}" << endl;
    }

    // Clean up memory for the 2D array
    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

// optimized

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;

        for (int i = 0; i < n; i++)
        {
            if (output.empty() || output.back()[1] < intervals[i][0])
            {
                output.push_back(intervals[i]);
            }
            else
            {
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            }
        }
        return output;
    }
};
