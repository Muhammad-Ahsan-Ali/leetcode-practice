#include <iostream>
using namespace std;

int *missingAndRepeatedValue(int array[][2], int numRows, int numCols, int elements)
{
    int simpleArray[elements] =
        {0};

    int *returnArray = new int[2];
    returnArray[0] = 0; // manually initialize each element
    returnArray[1] = 0;
    int minimum = array[0][0];
    int maxmium = array[0][0];
    int index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {

            if (minimum > array[i][j])
            {
                minimum = array[i][j];
            }
            if (maxmium < array[i][j])
            {
                maxmium = array[i][j];
            }
            simpleArray[index] = array[i][j];
            index++;
        }
    }

    int hash[maxmium + 2] = {0};

    for (size_t i = 0; i < elements; i++)
    {
        hash[simpleArray[i]]++;
    }

    for (int i = 0; i <= maxmium + 1; i++)
    {
        if (hash[i] == 2)
        {
            returnArray[0] = i;
        }
        if (hash[i] == 0 && returnArray[1] == 0)
        {
            returnArray[1] = i;
        }
    }

    return returnArray;
}

int main()
{
    int array[][2] = {{2, 2},
                      {3, 4}};

    // int array[][3] = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    int numElements = sizeof(array) / sizeof(array[0][0]);

    int numRows = sizeof(array) / sizeof(array[0]);

    int numCols = sizeof(array[0]) / sizeof(array[0][0]);

    int *missingArray = missingAndRepeatedValue(array, numRows, numCols, numElements);

    cout << "Repeated value: " << missingArray[0] << endl;
    cout << "Missing value: " << missingArray[1] << endl;

    return 0;
}

// mathemetical optimal

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        long long n = rows * cols; // Total numbers expected

        // s-sn=x-y
        // s-sn=x2-y2=(x+y)(x-y)

        long long s = 0, sn = (n * (n + 1)) / 2;
        long long s2 = 0, s2n = (n * (n + 1) * (2 * n + 1)) / 6;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                long long num = grid[i][j];
                s += num;
                s2 += num * num;
            }
        }

        long long val1 = s - sn;     // x - y
        long long val2 = (s2 - s2n); // x^2 - y^2

        long long val_sum = val2 / val1; // x + y

        long long x = (val1 + val_sum) / 2; // Repeated number
        long long y = x - val1;             // Missing number

        return {(int)x, (int)y};
    }
};
