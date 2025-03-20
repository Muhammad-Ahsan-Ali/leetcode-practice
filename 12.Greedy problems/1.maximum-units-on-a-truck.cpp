class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        int num_of_units = 0;

        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });

        for (int i = 0; i < n; i++)
        {
            if (boxTypes[i][0] <= truckSize)
            {
                truckSize -= boxTypes[i][0];
                num_of_units += boxTypes[i][0] * boxTypes[i][1];
            }
            else
            {
                num_of_units += (boxTypes[i][1] * truckSize);
                truckSize -= truckSize;
                break;
            }
        }
        return num_of_units;
    }
};