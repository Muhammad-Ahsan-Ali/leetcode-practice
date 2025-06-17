class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        unordered_set<int> st;
        queue<int> q;
        q.push(start);
        st.insert(start);
        int n = arr.size();

        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            if (arr[idx] == 0)
                return true;
            int nextInd = idx + arr[idx];
            if (nextInd < n && !st.contains(nextInd))
            {
                q.push(nextInd);
                st.insert(nextInd);
            }

            nextInd = idx - arr[idx];
            if (nextInd >= 0 && !st.contains(nextInd))
            {
                st.insert(nextInd);
                q.push(nextInd);
            }
        }
        return false;
    }
};