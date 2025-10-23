

class Solution
{
private:
    void dfs(vector<vector<int>> &image, int initialColor, int row, int col,
             int newColor, vector<int> &rowOffsets, vector<int> &colOffsets)
    {
        if (image[row][col] == newColor)
        {
            return;
        }

        image[row][col] = newColor;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + rowOffsets[i];
            int nextCol = col + colOffsets[i];

            if (nextRow >= 0 && nextRow < image.size() &&
                nextCol >= 0 && nextCol < image[0].size() &&
                image[nextRow][nextCol] == initialColor)
            {
                dfs(image, initialColor, nextRow, nextCol, newColor, rowOffsets, colOffsets);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        {
            int initialColor = image[sr][sc];
            if (initialColor == newColor)

                return image;
        }

        vector<int> rowOffsets = {-1, 0, 1, 0};
        vector<int> colOffsets = {0, -1, 0, 1};

        dfs(image, initialColor, sr, sc, newColor, rowOffsets, colOffsets);

        return image;
    }
};
