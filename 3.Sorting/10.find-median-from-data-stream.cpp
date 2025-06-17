class MedianFinder
{
private:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (mx.empty() || mx.top() > num)
            mx.push(num);
        else
            mn.push(num);

        if (mx.size() - mn.size() > 1)
        {
            mn.push(mx.top());
            mx.pop();
        }
        if (mn.size() > mx.size())
        {
            mx.push(mn.top());
            mn.pop();
        }
    }

    double findMedian()
    {

        if (mn.size() == mx.size())
            return (double)(mn.top() + mx.top()) / 2;

        return mx.top();
    }
};
