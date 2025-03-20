class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal_triangle(numRows);
        pascal_triangle[0].push_back(1);

        for (int i = 1; i < numRows; i++)
        {
            int ind = 0;
            while (ind <= i)
            {
                if (ind == 0 || ind == i)
                {
                    pascal_triangle[i].push_back(1);
                }
                else
                {
                    int val = pascal_triangle[i - 1][ind - 1] +
                              pascal_triangle[i - 1][ind];
                    pascal_triangle[i].push_back(val);
                }
                ind++;
            }
        }
        return pascal_triangle;
    }
};

// more sci_fi method

class Solution
{
    vector<int> generateRow(int row)
    {
        vector<int> res;
        long long ans = 1;
        res.push_back(ans);

        for (int col = 1; col < (row + 1) / 2; col++)
        {
            ans = ans * (row - col) / col;
            res[col] = ans;
            res[row - col - 1] = ans;
        }
        return res;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int row = 1; row <= numRows; row++)
        {
            res.push_back(generateRow(row));
        }
        return res;
    }
};
