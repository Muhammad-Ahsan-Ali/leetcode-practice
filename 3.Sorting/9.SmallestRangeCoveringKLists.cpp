
vector<int> smallestRange(vector<vector<int>> &nums)
{

    int len = nums.size();
  
    // Vector to hold (value, index of list) pairs
    vector<pair<int, int>> elements;

    // Populate the vector with (value, index of list) pairs
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            elements.push_back({nums[i][j], i});
        }
    }

    // Sort elements based on the value in ascending order
    sort(elements.begin(), elements.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    // Sliding window to find the smallest range that includes at least one number from each list
    map<int, int> countMap;
    int left = 0;
    int track = 0;
    int range = INT_MAX;
    // Keep track of the smallest range
    int minRange = 0, maxRange = 0;
    // These will store the minimum and maximum indices for the final range

    // To track how many lists have at least one element in the window

    for (int right = 0; right < elements.size(); right++)
    {
        countMap[elements[right].second]++;

        if (countMap[elements[right].second] == 1)
        {
            track++; // A new list is covered
        }

        // If all lists are covered, try to minimize the range
        while (track == len)
        {
            int currRange = elements[right].first - elements[left].first;
            if (currRange < range)
            {
                range = currRange;
                minRange = elements[left].first;
                maxRange = elements[right].first;
            }

            // Shrink the window from the left
            countMap[elements[left].second]--;

            if (countMap[elements[left].second] == 0)
            {
                track--; // A list is no longer fully covered
            }

            left++;
        }
    }

    return {minRange, maxRange};
}
