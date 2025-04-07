class Solution
{
private:
    void util(int sum, int index, vector<vector<int>> &ans, vector<int> temp,
              vector<int> &arr, int target)
    {

        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            if (i != index && arr[i] == arr[i - 1])
                continue;
            if (target < sum + arr[i])
                break;
            temp.push_back(arr[i]);
            util(sum + arr[i], i + 1, ans, temp, arr, target);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        vector<int> temp;

        util(0, 0, ans, temp, arr, target);

        return ans;
    }
};