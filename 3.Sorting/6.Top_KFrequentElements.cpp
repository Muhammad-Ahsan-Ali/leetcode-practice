 
vector<int> topKFrequent(vector<int> &nums, int k)
{
    int maxNum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        maxNum = max(maxNum, abs(nums[i]));
    }
    vector<vector<int>> hash(maxNum + 1, vector<int>(2, 0));

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            hash[nums[i]][0]++;
        }
        else
        {
            hash[abs(nums[i])][1]++;
        }
    }

    vector<int> resultantArray;

    int elementsLeft = nums.size();

    for (int i = 0; (i < k); i++)
    {
        int CurrMaxFreq = 0;
        int CurrMaxFreqNum = 0;
        int type = 0;
        for (int j = 0; j < maxNum + 1; j++)
        {
            if (CurrMaxFreq < hash[j][0])
            {
                CurrMaxFreq = hash[j][0];
                CurrMaxFreqNum = j;
                type = 0;
            }
            if (CurrMaxFreq < hash[j][1])
            {
                CurrMaxFreq = hash[j][1];
                CurrMaxFreqNum = -j;
                type = 1;
            }
        }
        elementsLeft = elementsLeft - CurrMaxFreq;
        hash[abs(CurrMaxFreqNum)][type] = 0;
        resultantArray.push_back(CurrMaxFreqNum);
    }
    return resultantArray;
}
 