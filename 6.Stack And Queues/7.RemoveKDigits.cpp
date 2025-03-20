
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
    std::string removeKdigits(std::string num, int k)
    {
        std::string result = ""; // Acts as our "stack" for building the result

        // Traverse through each digit in the input string
        for (char digit : num)
        {
            // While we can still remove digits (k > 0) and the last digit in result is greater
            // than the current digit, we remove the last digit (mimicking a stack pop).
            while (!result.empty() && k > 0 && result.back() > digit)
            {
                result.pop_back();
                k--;
            }

            // Append the current digit to the result if it's not a leading zero
            if (!result.empty() || digit != '0')
            {
                result.push_back(digit);
            }
        }

        // If we still need to remove digits (k > 0), remove from the end of the result
        while (k > 0 && !result.empty())
        {
            result.pop_back();
            k--;
        }

        // If the result is empty, return "0", else return the final result
        return result.empty() ? "0" : result;
    }
};