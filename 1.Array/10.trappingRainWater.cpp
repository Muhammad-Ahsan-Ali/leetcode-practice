#include <iostream>
using namespace std;

// int trappingRainWater(int array[], int length)
// {
//     int first_wall = 0;
//     int second_wall = 0;
//     int first_wall_index = 0;
//     int second_wall_index = 0;
//     int waterArray[length] = {0};
//     int watterTrapped = 0;
//     for (int i = 0; i < length; i++)
//     {
//         if (array[i] > first_wall)
//         {
//             first_wall = array[i];
//             first_wall_index = i;
//         }

//         for (int j = first_wall_index + 2; j < length; j++)
//         {
//             if (array[j] > second_wall)
//             {
//                 second_wall = array[j];
//                 second_wall_index = j;
//             }
//             for (int k = first_wall_index + 1; k < second_wall_index; k++)
//             {
//                 if (array[k] < second_wall && array[k] < first_wall)
//                 {
//                     int water = 0;
//                     if (second_wall >= first_wall)
//                     {
//                         water = first_wall - array[k];
//                     }
//                     if (first_wall > second_wall)
//                     {
//                         water = second_wall - array[k];
//                     }

//                     if (waterArray[k] < water)
//                     {
//                         waterArray[k] = water;
//                     }
//                 }
//             }
//         }
//         first_wall = 0;
//         second_wall = 0;
//     }

//     for (int i = 0; i < length; i++)
//     {
//         cout << waterArray[i] << " ";
//         watterTrapped += waterArray[i];
//     }
//     return watterTrapped;
// }

int trappingRainWater(int array[], int length)
{
    int first_wall[length] = {0};
    int second_wall[length] = {0};
    int maxTill = 0;
    int water = 0;

    for (int i = 0; i < length; i++)
    {
        if (maxTill < array[i])
        {
            maxTill = array[i];
        }
        first_wall[i] = maxTill;
    }

    maxTill = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        if (maxTill < array[i])
        {
            maxTill = array[i];
        }

        second_wall[i] = maxTill;
    }

    for (int i = 0; i < length; i++)
    {
        if (first_wall[i] < second_wall[i])
        {
            water += first_wall[i] - array[i];
        }
        else
        {
            water += second_wall[i] - array[i];
        }
    }

    return water;
}

int main()
{

    int array[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int lenght = sizeof(array) / sizeof(array[0]);
    cout << trappingRainWater(array, lenght);

    return 0;
}

// optimized
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0;
        int total = 0;
        int r = height.size() - 1;
        int lMax = 0;
        int rMax = 0;

        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (lMax > height[l])
                {
                    total += lMax - height[l];
                }
                else
                {
                    lMax = height[l];
                }

                l++;
            }
            else
            {
                if (rMax > height[r])
                {
                    total += rMax - height[r];
                }
                else
                {
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};