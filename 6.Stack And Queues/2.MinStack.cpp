#include <iostream>
#include <vector>
using namespace std;
class MinStack
{
private:
    vector<int> array;
    int size = -1;
    long long min;

public:
    MinStack() : size(-1), min(LLONG_MAX) {}

    void push(int val)
    {
        size++;
        array.push_back(val);
    }

    int pop()
    {

        int value = array[size];
        array.pop_back();
        size--;
        return value;
    }

    int top()
    {
        return array[size];
    }

    int getMin()
    {
        if (size == -1)
            return -1;

        min = array[0];

        for (int i = 1; i <= size; ++i)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }
};

int main()
{

    return 0;
}

// correct sol

class MinStack
{
private:
    vector<vector<int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int min_val = getMin();
        if (st.empty() || min_val > val)
        {
            min_val = val;
        }
        st.push_back({val, min_val});
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.empty() ? -1 : st.back()[0];
    }

    int getMin()
    {
        return st.empty() ? -1 : st.back()[1];
    }
};