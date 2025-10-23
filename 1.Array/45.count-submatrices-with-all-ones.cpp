class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {

        int r = mat.size();
        int c = mat[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = c - 2; j >= 0; j--)
            {
                if (mat[i][j])
                    mat[i][j] += mat[i][j + 1];
            }
        }

        int count = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int minWidth = mat[i][j];
                for (int cr = i; cr < r; cr++)
                {
                    if (mat[cr][j] == 0)
                        break;
                    else
                    {
                        minWidth = min(minWidth, mat[cr][j]);
                        count += minWidth;
                    }
                }
            }
        }

        return count;
    }
};

// optimized
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Helper to count the number of submatrices in a histogram row
    int countSubmatInHistogram(vector<int> &heights)
    {
        stack<int> s;
        int n = heights.size();
        vector<int> sum(n, 0);
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                int prev = s.top();
                sum[i] = sum[prev] + heights[i] * (i - prev);
            }
            else
            {
                sum[i] = heights[i] * (i + 1);
            }

            s.push(i);
            count += sum[i];
        }

        return count;
    }

    int numSubmat(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        vector<int> heights(c, 0);
        int total = 0;

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                // Build up histogram
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
            }
            // Use helper function to count rectangles in current histogram
            total += countSubmatInHistogram(heights);
        }

        return total;
    }
};
