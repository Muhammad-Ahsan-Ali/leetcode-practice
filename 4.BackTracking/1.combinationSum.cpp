 
void util(int sum, int index, vector<vector<int>> &combinations, vector<int> temp, vector<int> &candidates, int target)
{

    if (sum >= target || index >= candidates.size())
    {
        if (sum == target)
        {
            combinations.push_back(temp);
        }
        return;
    }

    temp.push_back(candidates[index]);
    util(sum + candidates[index], index, combinations, temp, candidates, target);
    temp.pop_back();
    util(sum, index + 1, combinations, temp, candidates, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> combinations;
    vector<int> temp;

    util(0, 0, combinations, temp, candidates, target);

    return combinations;
}
 