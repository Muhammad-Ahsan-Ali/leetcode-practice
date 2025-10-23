class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {

        map<int, vector<int>> ytox;
        for (auto p : points)
            ytox[p[1]].push_back(p[0]);

        unordered_map<long long, int> lastSeenRow;
        int area = INT_MAX;
        for (auto row : ytox)
        {
            int y = row.first;
            vector<int> &xs = row.second;
 
            for (int i = 0; i < xs.size(); i++)
            {
                for (int j = i + 1; j < xs.size(); j++)
                {
                    int x1 = xs[i];
                    int x2 = xs[j];

                    if (x1 > x2)
                        swap(x1, x2);
                    long long key = (long long)x1 * 40001 + x2;

                    if (lastSeenRow.contains(key))
                    {
                        int prevY = lastSeenRow[key];
                        int curArea = abs(x2 - x1) * abs(y - prevY);
                        area = min(area, curArea);
                    }

                    lastSeenRow[key] = y;
                }
            }
        }
        return area == INT_MAX ? 0 : area;
    }
};