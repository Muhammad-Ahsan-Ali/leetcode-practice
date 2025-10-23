class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {

        vector<vector<int>> yBucket(101);

        for (auto &r : rectangles)
            yBucket[r[1]].push_back(r[0]);

        for (size_t i = 0; i <= 100; i++)
        {
            auto &v = yBucket[i];
            sort(v.begin(), v.end());
        }

        vector<int> ans;

        for (auto &p : points)
        {
            int x = p[0], y = p[1];
            int cnt = 0;

            for (size_t qy = y; qy <= 100; qy++)
            {
                auto &v = yBucket[qy];
                cnt += v.end() - lower_bound(v.begin(), v.end(), x);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};