#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> array;

public:
    void push(int val)
    {
        array.push_back(val);
    }

    int pop()
    {
        int value = array.back();
        array.pop_back();
        return value;
    }

    int top()
    {
        return array.back();
    }

    bool empty()
    {
        return array.empty();
    }
};

// Find Next Smaller Element (NSE) for each element
vector<int> findNSE(vector<int> arr)
{
    Stack s;
    vector<int> output(arr.size());

    // Traverse from the end to the start of the array
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        // If stack is empty, no NSE, so store arr.size(), else store index of the next smaller element
        output[i] = s.empty() ? arr.size() : s.top();
        s.push(i);
    }

    return output;
}

// Find Previous Smaller Element (PSE) for each element
vector<int> findPSE(vector<int> arr)
{
    Stack s;
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            s.pop();
        }

        // If stack is empty, no PSE, so store -1, else store index of the previous smaller element
        output[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return output;
}

// Find Next Greater Element (NGE) for each element
vector<int> findNGE(vector<int> arr)
{
    Stack s;
    vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        output[i] = s.empty() ? arr.size() : s.top();
        s.push(i);
    }

    return output;
}

// Find Previous Greater Element (PGE) for each element
vector<int> findPGE(vector<int> arr)
{
    Stack s;
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            s.pop();
        }

        output[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return output;
}

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        // Finding next and previous smaller and greater elements
        vector<int> NSE = findNSE(nums);
        vector<int> PSE = findPSE(nums);
        vector<int> NGE = findNGE(nums);
        vector<int> PGE = findPGE(nums);

        long long total = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // Contribution as maximum element
            long long maxContribution = (long long)(i - PGE[i]) * (NGE[i] - i) * nums[i];

            // Contribution as minimum element
            long long minContribution = (long long)(i - PSE[i]) * (NSE[i] - i) * nums[i];

            // Add to total the difference
            total += maxContribution - minContribution;
        }

        return total;
    }
};

int main()
{

    return 0;
}