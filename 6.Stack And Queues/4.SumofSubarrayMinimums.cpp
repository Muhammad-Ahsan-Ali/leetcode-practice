#include <iostream>
#include <vector>
#include <map>
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
        // Maintain a decreasing stack

        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        // If stack is empty, no NSE, so store -1, else store index of the next smaller element
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

    // Traverse from the start to the end of the array
    for (int i = 0; i < arr.size(); i++)
    {
        // Maintain a decreasing stack
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
  
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {

        vector<int> NSE = findNSE(arr);
        vector<int> PSE = findPSE(arr);
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++)
        {
            long long left = i - PSE[i];

            long long right = NSE[i] - i;
            long long contribution = (left * right * arr[i]) % mod;
            total = (total + contribution) % mod;
        }

        return total;
    }
};

int main()
{

    return 0;
}