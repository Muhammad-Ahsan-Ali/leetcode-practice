#include <iostream>
#include <cstring>
using namespace std;

void reverseArray(char array[], int lenght)
{
    char temp;
    for (int i = 0; i <= lenght - i; i++)
    {
        temp = array[i];
        array[i] = array[lenght - 1 - i];
        array[lenght - 1 - i] = temp;
    }
}

int main()
{

    char array[10] = {'h', 'e', 'l', 'l', 'o'};

    int lenght = strlen(array);

    reverseArray(array, lenght);

    for (size_t i = 0; i < lenght; i++)
    {
        cout << array[i];
    }

    return 0;
}