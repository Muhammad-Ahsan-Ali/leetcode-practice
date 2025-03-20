class Solution
{
    // Struct to represent a job with start time, end time, and profit
    struct job
    {
        int start;
        int end;
        int profit;

        // Constructor to initialize a job
        job(int s, int e, int p) : start(s), end(e), profit(p) {}
    };

    // Binary search function to find the first job that starts after a given job's end time
    int lowerBound(vector<job> &jobs, int target)
    {
        int low = 0, high = jobs.size();

        while (low < high)
        {
            int mid = (low + high) / 2;

            // If the current job starts before the target end time, search in the right half
            if (jobs[mid].start < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid; // Possible answer found, continue searching in the left half
            }
        }
        return low; // Returns the first index where job.start >= target
    }

    // Recursive function with memoization to find the maximum profit
    int maxProfit(vector<job> &jobs, int ind, vector<int> &dp)
    {
        // Base case: If we have processed all jobs
        if (ind >= jobs.size())
        {
            return 0;
        }

        // If result is already computed, return it (Memoization)
        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        // Find the index of the next non-overlapping job using binary search
        int nextInd = lowerBound(jobs, ind + 1, jobs[ind].end);

        // Choose the maximum of:
        // 1. Skipping the current job
        // 2. Taking the current job and adding the profit of the next possible job
        return dp[ind] = max(maxProfit(jobs, ind + 1, dp), jobs[ind].profit + maxProfit(jobs, nextInd, dp));
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = endTime.size();
        vector<job> jobs;
        vector<int> dp(n, -1); // DP array initialized to -1 for memoization

        // Populate the jobs array
        for (int i = 0; i < n; i++)
        {
            jobs.push_back(job(startTime[i], endTime[i], profit[i]));
        }

        // Sort jobs by start time to ensure correctness in DP computation
        sort(jobs.begin(), jobs.end(), [](const job &a, const job &b)
             { return a.start < b.start; });

        // Call the recursive function starting from index 0
        return maxProfit(jobs, 0, dp);
    }
};

// optimized

class Solution
{
    struct job
    {
        int start;
        int end;
        int profit;

        job(int s, int e, int p) : start(s), end(e), profit(p) {}
    };

    // Binary search function to find the first job that starts after or at the current job's end time
    int lowerBound(vector<job> &jobs, int target)
    {
        int low = 0, high = jobs.size();

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (jobs[mid].start < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = endTime.size();
        vector<job> jobs;

        // Populate the jobs array
        for (int i = 0; i < n; i++)
        {
            jobs.push_back(job(startTime[i], endTime[i], profit[i]));
        }

        // Sort jobs by start time for correct DP processing
        sort(jobs.begin(), jobs.end(), [](const job &a, const job &b)
             { return a.start < b.start; });

        // DP array to store the maximum profit at each index
        vector<int> dp(n + 1, 0);

        // Bottom-up DP computation
        for (int i = n - 1; i >= 0; i--)
        {
            // Find the index of the next non-overlapping job
            int nextInd = lowerBound(jobs, jobs[i].end);

            // Two choices: Skip this job or take it and add profit from next non-overlapping job
            dp[i] = max(dp[i + 1], jobs[i].profit + dp[nextInd]);
        }

        return dp[0]; // The answer is stored at dp[0]
    }
};
