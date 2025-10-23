class Solution
{
private:
    int getArea(vector<vector<int>> &corners)
    {

        vector<int> bottomLeft = corners[0];
        vector<int> topLeft = corners[1];
        vector<int> bottomRight = corners[2];
        vector<int> topRight = corners[3];
        if (bottomLeft[0] != topLeft[0] || bottomRight[0] != topRight[0])
            return -1;
        if (bottomLeft[1] != bottomRight[1] || topLeft[1] != topRight[1])
            return -1;

        return abs(bottomRight[0] - bottomLeft[0]) *
               abs(topLeft[1] - bottomLeft[1]);
    }

    bool hasInternalPoints(vector<vector<int>> &points,
                           vector<vector<int>> &corners)
    {

        vector<int> bottomLeft = corners[0];
        vector<int> topLeft = corners[1];
        vector<int> bottomRight = corners[2];
        vector<int> topRight = corners[3];
        for (auto point : points)
        {
            if (point == bottomLeft || point == topLeft ||
                point == bottomRight || point == topRight)
                continue;
            int x = point[0];
            int y = point[1];
            if (x >= bottomLeft[0] && x <= bottomRight[0] &&
                y >= bottomRight[1] && y <= topRight[1])
                return true;
        }
        return false;
    }

public:
    int maxRectangleArea(vector<vector<int>> &points)
    {

        int n = points.size();
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        vector<vector<int>> corners = {points[i], points[j],
                                                       points[k], points[l]};
                        sort(corners.begin(), corners.end());

                        int area = getArea(corners);
                        if (area == -1 || hasInternalPoints(points, corners))
                            continue;
                        ans = max(area, ans);
                    }
                }
            }
        }
        return ans;
    }
};