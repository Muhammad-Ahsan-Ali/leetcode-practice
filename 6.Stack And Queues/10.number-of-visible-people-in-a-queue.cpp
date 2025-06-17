class Stack
{
private:
    vector<int> array;

public:
    bool isempty() { return array.empty(); };
    void push(int value) { array.push_back(value); };
    int pop()
    {
        int value = array.back();
        array.pop_back();
        return value;
    }
    int top() { return array.back(); }
};

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        Stack s;
        int size = heights.size();
        vector<int> returningArray(size, 0);

        for (int i = size - 1; i >= 0; i--)
        {
            int sight = 0;

            while (!s.isempty() && heights[i] > heights[s.top()])
            {
                s.pop();
                sight++;
            }

            if (!s.isempty())
            {
                sight++;
            }
            s.push(i);
            returningArray[i] = sight;
        }

        return returningArray;
    }
};
