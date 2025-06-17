class Stack
{
private:
    vector<int> array;

public:
    void push(int val)
    {
        array.push_back(val);
    }

    int pop()
    {
        int value = array.back();
        array.pop_back();
        return value;
    }

    int top()
    {
        return array.back();
    }

    bool empty()
    {
        return array.empty();
    }
};

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;

        vector<int> tempArray(col, 0);

        for (int i = 0; i < row; i++)
        {
            // Update the histogram heights
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '0')
                {
                    tempArray[j] = 0;
                }
                else
                {
                    tempArray[j] += (matrix[i][j] - '0');
                }
            }

            // Compute the maximum area for the current histogram
            Stack s;

            for (int k = 0; k < col; k++)
            {
                while (!s.empty() && tempArray[s.top()] > tempArray[k])
                {
                    int element = s.top();
                    s.pop();
                    int pse = s.empty() ? -1 : s.top();
                    int nse = k;
                    maxArea = max(tempArray[element] * (nse - pse - 1), maxArea);
                }
                s.push(k);
            }

            while (!s.empty())
            {
                int element = s.top();
                s.pop();
                int pse = s.empty() ? -1 : s.top();
                int nse = col;
                maxArea = max(tempArray[element] * (nse - pse - 1), maxArea);
            }
        }

        return maxArea;
    }
};
