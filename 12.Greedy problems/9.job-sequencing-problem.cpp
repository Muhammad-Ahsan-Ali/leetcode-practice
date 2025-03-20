class Solution
{
    // Structure to represent a job
    struct job
    {
        int id;     // Job ID
        int end;    // Job deadline
        int profit; // Profit from the job

        // Constructor to initialize a job with id, deadline, and profit
        job(int d, int e, int p) : id(d), end(e), profit(p) {}
    };

public:
    // Function to perform job sequencing and maximize profit
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size(); // Number of jobs
        int maxDeadline = 0;     // Variable to track the maximum deadline

        vector<job> jobs; // Vector to store job details

        // Loop to create job objects and add them to the vector
        for (int i = 0; i < n; i++)
        {
            jobs.push_back(job(id[i], deadline[i], profit[i]));
        }

        // Sorting jobs in descending order of profit to prioritize high-profit jobs
        sort(jobs.begin(), jobs.end(), [](const job &a, const job &b)
             { return a.profit > b.profit; });

        // Finding the maximum deadline among all jobs
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Hash table (array) to keep track of job scheduling
        vector<int> hash(maxDeadline, -1); // Initialized with -1 (empty slots)
        int maxProfit = 0;                 // Variable to track total profit
        int count = 0;                     // Variable to track the number of jobs scheduled

        // Iterating through sorted jobs to schedule them
        for (int i = 1; i < n; i++)
        {
            // Finding a free time slot from job's deadline towards the start
            for (int j = jobs[i].end; j > 0; j--)
            {
                if (hash[j] == -1) // If the slot is available
                {
                    hash[j] = jobs[i].id;        // Assign the job to the slot
                    maxProfit += jobs[i].profit; // Add job's profit to total profit
                    count++;                     // Increase count of scheduled jobs
                    break;                       // Move to the next job
                }
            }
        }

        // Returning the number of jobs scheduled and the total profit
        return {count, maxProfit};
    }
};
