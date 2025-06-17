
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

class StockSpanner
{
    Stack s;
    Stack sIndex;
    int priceIndex;

public:
    StockSpanner() : priceIndex(0) {}

    int next(int price)
    {
        int span = 1;

        while (!s.empty() && s.top() <= price)
        {
            s.pop();
            span += sIndex.top();
            sIndex.pop();
        }

        s.push(price);
        sIndex.push(span);

        priceIndex++;

        return span;
    }
};
