class Solution
{
public:
    int minCost(vector<int> &arr)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &&i : arr)
        {
            pq.push(i);
        }
        int ans = 0;
        while (pq.size() != 1)
        {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            ans += f + s;
            pq.push(f + s);
        }
        return ans;
    }
};
