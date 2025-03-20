#include <iostream>
using namespace std;

int maxProfit(int array[], int length)
{
    int maxProfit = 0;
    int curr = 0;
    int diff[length - 1];
    int size = length - 1;
    for (int i = 1; i < length; i++)
    {
        diff[i] = array[i] - array[i - 1];
    }

    for (int i = 0; i < size; i++)
    {
        curr += diff[i];
        if (curr < 0)
        {
            curr = 0;
        }
        if (curr > maxProfit)
        {
            maxProfit = curr;
        }
    }

    return maxProfit;
}

int main()
{

    int array[] = {7, 1, 5, 3, 6, 4};

    int lenght = sizeof(array) / sizeof(array[0]);

    cout << maxProfit(array, lenght);

    return 0;
}