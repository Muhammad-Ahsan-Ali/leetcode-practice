class Solution
{
public:
    bool canTransform(string start, string result)
    {
        int i = 0, j = 0;

        if (start.length() != result.length())
            return 0;
        int n = start.length();

        while (i < n || j < n)
        {
            while (i < n && start[i] == 'X')
                i++;
            while (j < n && result[j] == 'X')
                j++;

            if (i == n && j == n)
                return 1;
            if (i == n || j == n)
                return 0;

            if (start[i] != result[j])
                return 0;

            if (start[i] == 'L' && i < j)
                return 0;
            if (start[i] == 'R' && i > j)
                return 0;
            i++;
            j++;
        }
        return 1;
    }
};