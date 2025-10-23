class DetectSquares
{
    unordered_map<int, int> cnt;

public:
    DetectSquares() {}

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        int key = 1001 * x + y;
        cnt[key]++;
    }

    int count(vector<int> point)
    {
        int qx = point[0];
        int qy = point[1];
        int ways = 0;

        for (auto cur : cnt)
        {
            int key = cur.first;
            int x = key / 1001;
            int y = key % 1001;
            if (x == qx || y == qy)
                continue;
            if (abs(x - qx) == abs(y - qy))
            {
                int key1 = 1001 * qx + y;
                int key2 = 1001 * x + qy;

                auto it1 = cnt.find(key1);
                auto it2 = cnt.find(key2);

                if (it1 == cnt.end() || it2 == cnt.end())
                    continue;

                ways += cnt[key1] * cnt[key2] * cur.second;
            }
        }
        return ways;
    }
};

// other approach
class DetectSquares
{
    // cnt[x][y] = number of times point (x, y) has been added
    unordered_map<int, unordered_map<int, int>> cnt;

public:
    DetectSquares() {}

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        cnt[x][y]++;
    }

    int count(vector<int> point)
    {
        int qx = point[0];
        int qy = point[1];
        int ways = 0;

        // iterate through all stored points
        for (auto &px : cnt)
        {
            int x = px.first;
            for (auto &py : px.second)
            {
                int y = py.first;
                int freq = py.second;

                if (x == qx || y == qy)
                    continue;
                if (abs(x - qx) == abs(y - qy))
                {
                    // check the other two corners
                    if (cnt[qx].count(y) && cnt[x].count(qy))
                    {
                        ways += freq * cnt[qx][y] * cnt[x][qy];
                    }
                }
            }
        }
        return ways;
    }
}; 
