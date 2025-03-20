#include <iostream>
using namespace std;

void findMinDiff(int array[], int m, int length)
{

    int minDif = 999999;

    for (int i = 1; i < length; i++)
    {

        for (int j = 0; j < length; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    for (int i = m - 1; i < length; i++)
    {
        int temp = array[i] - array[i - (m - 1)];
        if (minDif > temp)
        {
            minDif = temp;
        }
    }
    cout << minDif;
}

int main()
{

    int array[] = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;

    int length = sizeof(array) / sizeof(array[0]);

    findMinDiff(array, m, length);
    // for (size_t i = 0; i < length; i++)
    // {
    //     cout << array[i];
    // }

    return 0;
}