class Solution
{
public:
    int tilingRectangle(int n, int m)
    {

        if (n < m)
            swap(m, n);

        vector<int> heights(m, 0);

        int res = INT_MAX;

        function<vector<int>(vector<int> &, int, int)> update =
            [&](vector<int> &currHeights, int sqSz,
                int leftSide) -> vector<int>
        {
            vector<int> t = currHeights;
            for (int i = 0; i < sqSz; i++)
                t[i + leftSide] += sqSz;
            return t;
        };

        function<void(vector<int>, int)> dfs = [&](vector<int> heightsP,
                                                   int usedSqures) -> void
        {
            if (usedSqures >= res)
                return;

            int minHeight = INT_MAX;
            int leftSide;
            for (int i = 0; i < heightsP.size(); i++)
                if (heightsP[i] < minHeight)
                {
                    minHeight = heightsP[i];
                    leftSide = i;
                }

            if (minHeight == n)
            {
                res = min(usedSqures, res);
                return;
            }

            int rightSide = leftSide;

            while (rightSide < m && heightsP[rightSide] == minHeight)
            {
                rightSide++;
            }

            int maxSizeSqure = min(rightSide - leftSide, n - minHeight);

            for (int h = maxSizeSqure; h > 0; h--)
            {
                auto upHeights = update(heightsP, h, leftSide);
                dfs(upHeights, usedSqures + 1);
            }
        };

        dfs(heights, 0);
        return res;
    }
};

// optimization

class Solution
{
public:
    int tilingRectangle(int n, int m)
    {
        if (n < m)
            swap(n, m);

        vector<int> heights(m, 0);
        int minTiles = INT_MAX;

        function<void(int)> dfs = [&](int usedTiles)
        {
            if (usedTiles >= minTiles)
                return;

            int minHeight = INT_MAX, leftIndex;
            for (int i = 0; i < m; i++)
                if (heights[i] < minHeight)
                {
                    minHeight = heights[i];
                    leftIndex = i;
                }

            if (minHeight == n)
            {
                minTiles = min(minTiles, usedTiles);
                return;
            }

            int rightIndex = leftIndex;
            while (rightIndex < m && heights[rightIndex] == minHeight)
                rightIndex++;

            int maxSquareSize = min({n - minHeight, rightIndex - leftIndex});

            for (int size = maxSquareSize; size >= 1; size--)
            {
                for (int i = 0; i < size; i++)
                    heights[leftIndex + i] += size;

                dfs(usedTiles + 1);

                for (int i = 0; i < size; i++)
                    heights[leftIndex + i] -= size;
            }
        };

        dfs(0);
        return minTiles;
    }
};
