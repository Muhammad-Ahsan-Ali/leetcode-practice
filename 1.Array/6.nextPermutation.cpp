#include <iostream>
using namespace std;

void nextPermutaion(int array[], int lenght)
{
    int pivot = -1;
    int j = lenght - 1;

    for (int i = lenght - 2; i >= 0; i--)
    {
        if (array[i] < array[i + 1])
        {
            pivot = i;
            break;
        }
    }

    int sufftix_start = pivot + 1;

    if (pivot != -1)
    {

        for (int i = lenght - 1; i > pivot; i--)
        {
            if (array[i] > array[pivot])
            {
                // Swap the pivot with this element
                int temp = array[i];
                array[i] = array[pivot];
                array[pivot] = temp;
                break;
            }
        }
    }

    while (sufftix_start < j)
    {
        // Swap elements at the sufftix_start and j positions
        int temp = array[sufftix_start];
        array[sufftix_start] = array[j];
        array[j] = temp;
        sufftix_start++;
        j--;
    }
}

int main()
{

    int array[] = {2, 3, 1};

    int lenght = sizeof(array) / sizeof(array[0]);

    nextPermutaion(array, lenght);

    for (size_t i = 0; i < lenght; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}