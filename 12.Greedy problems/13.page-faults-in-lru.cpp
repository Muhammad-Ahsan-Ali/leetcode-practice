#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// Class that contains the method to calculate page faults
class Solution
{
public:
    // Function to calculate the number of page faults
    int pageFaults(int N, int C, int pages[])
    {
        unordered_set<int> cache; // Hash set to store pages currently in cache
        queue<int> order;         // Queue to maintain the order of page requests
        int pageFaults = 0;       // Counter for page faults

        for (int i = 0; i < N; i++) // Loop through each page request
        {
            // If the page is not found in the cache (a page fault occurs)
            if (cache.find(pages[i]) == cache.end())
            {
                pageFaults++; // Increment the page fault count

                // If the cache is full, remove the oldest page
                if (cache.size() == C)
                {
                    int oldest = order.front(); // Get the oldest page
                    order.pop();                // Remove it from the order queue
                    cache.erase(oldest);        // Remove it from the cache set
                }

                // Insert the new page into the cache and update the order queue
                cache.insert(pages[i]);
                order.push(pages[i]);
            }
            else // If the page is already in the cache (a hit)
            {
                // Reorder the queue to move the accessed page to the back
                queue<int> tempQueue;
                while (!order.empty())
                {
                    if (order.front() != pages[i])
                        tempQueue.push(order.front());
                    order.pop();
                }
                tempQueue.push(pages[i]); // Move the accessed page to the back
                swap(order, tempQueue);   // Swap the old queue with the new one
            }
        }
        return pageFaults; // Return the total number of page faults
    }
};
