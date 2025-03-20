class Solution
{
private:
  int mcm(vector<int> &arr, int i, int j)
  {
    if (i >= j)
      return 0;

    int minCost = INT_MAX; // Use INT_MAX instead of 1e9

    for (int k = i; k < j; k++)
    {
      int cost = (arr[i - 1] * arr[k] * arr[j]) + mcm(arr, i, k) + mcm(arr, k + 1, j);
      minCost = min(minCost, cost);
    }

    return minCost;
  }

public:
  int matrixMultiplication(vector<int> &arr)
  {
    int n = arr.size();
    return mcm(arr, 1, n - 1); // Pass 1 and n-1 as valid indices
  }
};
