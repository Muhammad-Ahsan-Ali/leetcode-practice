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

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        Stack s;
        int maxArea = 0;
 
        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[s.top()] > heights[i])
            {
                int element = heights[s.top()];
                s.pop();
                int nse = i;
                int pse = s.empty() ? -1  : s.top();
                maxArea = max((element * (nse - pse - 1)), maxArea);
            }
            s.push(i);
        }

        while (!s.empty())
        {
            int element = heights[s.pop()];
            int nse = heights.size();
            int pse = s.empty() ? -1 : s.top();
            maxArea = max((element * (nse - pse - 1)), maxArea);
        }

        return maxArea;
    }
};

int main()
{

    return 0;
}