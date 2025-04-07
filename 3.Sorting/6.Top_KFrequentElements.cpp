
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

// nlog k

class Solution
{
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        // map pair is <ele,freq>
        for (auto ele : nums)
            m[ele]++;
        
        // heap pair is <freq,ele>
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (auto x : m)
        {
            int ele = x.first, freq = x.second;
            pi p = {freq, ele};
            pq.push(p);
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty())
        {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        
        return ans;
    }
};

// o3n

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        vector<int> output;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(n + 1, vector<int>(0)); // i = frequnccy of elements at buck[i]

        for (auto &it : mp)
        {
            int val = it.first;
            int freq = it.second;
            bucket[freq].push_back(val);
        }

        for (int i = n; i >= 0; i--)
        {
            while (bucket[i].size() > 0 && k > 0)
            {
                output.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return output;
    }
};