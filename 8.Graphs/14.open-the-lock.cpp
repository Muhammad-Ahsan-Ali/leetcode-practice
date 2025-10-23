class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {

        unordered_set<string> st(deadends.begin(), deadends.end());
        queue<pair<string, int>> q;
        if (!st.contains("0000"))
            q.push({"0000", 0});
        st.insert("0000");

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            string pattern = it.first;
            int turns = it.second;

            if (pattern == target)
                return turns;

            for (int i = 0; i < 4; i++)
            {
                string temp = pattern;
                int digit = temp[i] - '0';
                int decre = (digit + 9) % 10;
                int incre = (digit + 1) % 10;

                temp[i] = decre + '0';
                if (!st.contains(temp))
                {
                    st.insert(temp);
                    q.push({temp, turns + 1});
                }

                temp[i] = incre + '0';
                if (!st.contains(temp))
                {
                    st.insert(temp);
                    q.push({temp, turns + 1});
                }
            }
        }

        return -1;
    }
};

// optimized
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.contains("0000"))
            return -1;
        if (target == "0000")
            return 0;

        unordered_set<string> q1, q2; // two frontiers
        q1.insert("0000");
        q2.insert(target);

        visited.insert("0000");
        visited.insert(target);

        int turns = 0;

        while (!q1.empty() && !q2.empty())
        {
            if (q1.size() > q2.size())
                swap(q1, q2);

            unordered_set<string> next;
            for (auto pattern : q1)
            {
                for (int i = 0; i < 4; i++)
                {
                    char ch = pattern[i];
                    int d = ch - '0';

                    // try -1
                    int decre = (d + 9) % 10;
                    string temp = pattern;
                    temp[i] = decre + '0';

                    if (q2.contains(temp))
                        return turns + 1;
                    if (!visited.contains(temp))
                    {
                        visited.insert(temp);
                        next.insert(temp);
                    }

                    // try +1
                    int incre = (d + 1) % 10;
                    temp = pattern;
                    temp[i] = incre + '0';

                    if (q2.contains(temp))
                        return turns + 1;
                    if (!visited.contains(temp))
                    {
                        visited.insert(temp);
                        next.insert(temp);
                    }
                }
            }

            q1 = move(next);
            turns++;
        }

        return -1;
    }
};
