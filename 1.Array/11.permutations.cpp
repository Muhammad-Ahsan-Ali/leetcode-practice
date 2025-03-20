#include <iostream>
#include <vector>
using namespace std;
static int index = 0;

void permuteHelper(vector<int> &nums, int index, vector<vector<int>> &result)
{
    int len = nums.size();

    // Base case: if index reaches the end, store the current permutation
    if (index >= len)
    {
        result.push_back(nums);
        return;
    }

    // Recursive case: iterate and generate permutations
    for (int i = index; i < len; i++)
    {
        swap(nums[i], nums[index]);             // Swap elements to generate a new permutation
        permuteHelper(nums, index + 1, result); // Recur with the next index
        swap(nums[i], nums[index]);             // Backtrack to restore the original state
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;     // Store all permutations
    permuteHelper(nums, 0, result); // Start recursion from index 0
    return result;
}

// vector<vector<int>> permute(vector<int> &nums)
// {
//     int len = nums.size();
//     static vector<vector<int>> returningArray;

//     if (index > len - 1)
//     {
//         returningArray.push_back(nums);
//         for (size_t j = 0; j < returningArray[index].size(); j++)
//         {
//             cout << returningArray[index][j] << " ";
//         }
//         cout << endl;
//         return returningArray;
//     }

//     for (int i = index; i < len; i++)
//     {

//         swap(nums[i], nums[index]);
//         index++;
//         permute(nums);
//         swap(nums[i], nums[index]);
//         // returningArray.push_back(nums);
//         // index++;
//     }

//     // permute(nums);
//     // index--;

//     // index++;

//     // permute(nums);

//     // for (int i = 0; i < len; i++)
//     // {
//     //     for (int j = 0; j < len; j++)
//     //     {
//     //         if (i != j)
//     //         {
//     //             swap(nums[i], nums[j]);
//     //             returningArray.push_back(nums);
//     //         }
//     //     }
//     // }

//     for (int i = 0; i < returningArray.size(); i++)
//     {
//         for (size_t j = 0; j < returningArray[i].size(); j++)
//         {
//             cout << returningArray[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return returningArray;
// }

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<vector<int>> returningArray = permute(nums);

    for (int i = 0; i < returningArray.size(); i++)
    {
        for (size_t j = 0; j < returningArray[i].size(); j++)
        {
            cout << returningArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}