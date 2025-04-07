 
vector<int> majorityElement(vector<int> &nums)
{

    // Hash map MEthOD

    // vector<int> resultArray;

    // if (nums.size() == 0)
    // {
    //     return resultArray; // Returning empty resultArray instead of {}
    // }

    // // Find the maximum value in the nums array
    // int max = nums[0];
    // int min = nums[0];
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (max < nums[i])
    //     {
    //         max = nums[i];
    //     }
    //     if (min > nums[i])
    //     {
    //         min = nums[i];
    //     }
    // }

    // // Create a hashTable with size (max + 1) to avoid index out of bounds
    // int totaLHashSize;
    // if (abs(min) > max)
    // {
    //     totaLHashSize = abs(min);
    // }
    // else
    // {
    //     totaLHashSize = max;
    // }

    // vector<vector<int>> hashTable(totaLHashSize + 1, vector<int>(2, 0));

    // // Check for elements that appear more than nums.size() / 3
    // int minFreq = nums.size() / 3;

    // for (int i = 0; i < nums.size(); i++)
    // {

    //     if (nums[i] >= 0)
    //     {
    //         hashTable[nums[i]][0]++;
    //         if (hashTable[nums[i]][0] > minFreq)
    //         {
    //             resultArray.push_back(nums[i]);
    //             hashTable[nums[i]][0] = -999999; // Set to an invalid value to avoid duplicates
    //         }
    //     }
    //     else
    //     {
    //         hashTable[abs(nums[i])][1]++;
    //         if (hashTable[abs(nums[i])][1] > minFreq)
    //         {
    //             resultArray.push_back(nums[i]);
    //             hashTable[abs(nums[i])][1] = -999999; // Set to an invalid value to avoid duplicates
    //         }
    //     }
    // }

    // Boyer MOORE Algorithm

    vector<int> resultArray;
    int count1 = 0, Num1 = 0;
    int count2 = 0, Num2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == Num1)
        {
            count1++;
        }
        else if (nums[i] == Num2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            Num1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            Num2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == Num1)
        {
            count1++;
        }
        else if (nums[i] == Num2)
        {
            count2++;
        }
    }

    int thresHold = nums.size() / 3;
    if (count1 > thresHold)
    {
        resultArray.push_back(Num1);
    }
    if (count2 > thresHold)
    {
        resultArray.push_back(Num2);
    }

    return resultArray;
}

int main()
{
    vector<int> nums = {2, 1, 1, 3, 1, 4, 5, 6};

    vector<int> resultantArray = majorityElement(nums);
    for (int i = 0; i < resultantArray.size(); i++)
    {
        cout << resultantArray[i];
    }

    return 0;
}