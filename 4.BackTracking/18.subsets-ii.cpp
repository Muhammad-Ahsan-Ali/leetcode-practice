

class Solution
{
private:
    void util(int index, vector<vector<int>> &ans, vector<int> temp,
              vector<int> &arr)
    {

        ans.push_back(temp);

        for (int i = index; i < arr.size(); i++)
        {
            if (i != index && arr[i] == arr[i - 1])
                continue;

            temp.push_back(arr[i]);
            util(i + 1, ans, temp, arr);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        vector<int> temp;

        util(0, ans, temp, nums);

        return ans;
    }
};