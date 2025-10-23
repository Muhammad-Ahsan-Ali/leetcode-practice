class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int ans = 0;
        int n = customers.size();

        for (int i = 0; i < n; i++)
            if (!grumpy[i])
                ans += customers[i];

        int extra = 0;
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i])
                extra += customers[i];
        }

        int window = extra;
        int i = 0;
        int j = minutes;
        while (j < n)
        {
            if (grumpy[i])
                window -= customers[i];
            i++;
            if (grumpy[j])
                window += customers[j];
            j++;
            extra = max(window, extra);
        }
        return ans + extra;
    }
};

// chat gpt code
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int alwaysSatisfied = 0;

        // Calculate always satisfied customers (grumpy == 0)
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
            {
                alwaysSatisfied += customers[i];
            }
        }

        // Calculate maximum extra satisfied customers in a window of size 'minutes'
        int extra = 0, maxExtra = 0;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 1)
            {
                extra += customers[i];
            }
            if (i >= minutes)
            {
                if (grumpy[i - minutes] == 1)
                {
                    extra -= customers[i - minutes];
                }
            }
            maxExtra = max(maxExtra, extra);
        }

        return alwaysSatisfied + maxExtra;
    }
};
