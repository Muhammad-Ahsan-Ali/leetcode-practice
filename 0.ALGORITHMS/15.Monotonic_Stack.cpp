#include <vector>
#include <stack>
using namespace std;

// Find Next Smaller Element (NSE)
vector<int> findNSE(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        output[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    return output;
}

// Find Previous Smaller Element (PSE)
vector<int> findPSE(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        output[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return output;
}

// Find Next Greater Element (NGE)
vector<int> findNGE(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();

        output[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    return output;
}

// Find Previous Greater Element (PGE)
vector<int> findPGE(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();

        output[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return output;
}
