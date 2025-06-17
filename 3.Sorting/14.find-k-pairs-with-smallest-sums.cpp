class Solution
{
    typedef pair<int, pair<int, int>> P;

public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        priority_queue<P, vector<P>, greater<P>> pq;

        unordered_set<pair<int, int>> vis;
        vis.insert({0, 0});
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vector<vector<int>> res;

        while (k-- && !pq.empty())
        {
            auto [sum, ij] = pq.top();
            int i = ij.first;
            int j = ij.second;

            res.push_back({nums1[i], nums1[j]});

            if (i + 1 < n && !vis.contains({i + 1, j}))
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }

            if (j + 1 < m && !vis.contains({i, j + 1}))
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }

        return res;
    }
};