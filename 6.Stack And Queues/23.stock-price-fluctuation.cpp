class StockPrice
{
    using pi = pair<int, int>; // {price, timestamp}

    priority_queue<pi> maxPq;                          // max-heap by price
    priority_queue<pi, vector<pi>, greater<pi>> minPq; // min-heap by price
    unordered_map<int, int> mp;                        // timestamp -> price
    int lastTimestamp = 0;

public:
    StockPrice() {}

    void update(int timestamp, int price)
    {
        mp[timestamp] = price;
        lastTimestamp = max(lastTimestamp, timestamp);

        maxPq.push({price, timestamp});
        minPq.push({price, timestamp});
    }

    int current()
    {
        return mp[lastTimestamp];
    }

    int maximum()
    {
        while (!maxPq.empty())
        {
            auto [price, ts] = maxPq.top();
            if (mp[ts] == price)
                return price;
            maxPq.pop();
        }
        return -1;
    }

    int minimum()
    {
        while (!minPq.empty())
        {
            auto [price, ts] = minPq.top();
            if (mp[ts] == price)
                return price;
            minPq.pop();
        }
        return -1;
    }
};
