// for positive ,zero and negative numbers

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        map<int, int> preSumMap;

        int maxLen = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;

            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }

        }
        return maxLen;
    }
};

// for positive ,zero only

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {

        int left = 0;
        int right = 0;
        int n = arr.size();
        int sum = arr[0];
        int maxLen = 0;
    
        while (right < n)
        {
            while (left <= right && sum > k)
            {
                sum -= arr[left];
                left++;
            }
        
            if (sum == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;

            if (right < n)
            {
                sum += arr[right];
            }

        }
        return maxLen;
    }
};