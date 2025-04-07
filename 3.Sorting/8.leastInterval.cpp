
//-------------sol-------------//

int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> hash;
    int maxFreq = 0;
    char maxTask; // To store the task with max frequency

    // Count frequencies and track max frequency task
    for (char task : tasks)
    {
        hash[task]++;
        if (hash[task] > maxFreq)
        {
            maxFreq = hash[task];
            maxTask = task;
        }
    }

    // Calculate ideal idle slots
    int ideal = (maxFreq - 1) * n;

    // Remove the most frequent task from hash before adjusting ideal
    hash.erase(maxTask);

    // Reduce idle slots by placing other frequent tasks
    for (auto &it : hash)
    {
        ideal -= min(maxFreq - 1, it.second);
    }

    return tasks.size() + max(ideal, 0);
}
