class Solution
{
private:
    int distSq(vector<int> &a, vector<int> &b)
    {

        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return x * x + y * y;
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                     vector<int> &p4)
    {

        vector<vector<int>> points = {p1, p2, p3, p4};
        vector<int> dists;
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
                dists.push_back(distSq(points[i], points[j]));

        sort(dists.begin(), dists.end());

        return dists[0] > 0 &&
               dists[0] == dists[1] &&
               dists[1] == dists[2] &&
               dists[2] == dists[3] &&
               dists[4] == dists[5] &&
               dists[5] == 2 * dists[0];
    }
};
