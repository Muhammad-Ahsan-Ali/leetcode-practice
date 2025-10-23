class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), [](auto &a, auto &b)
             { return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0]; });

        int maxDefense = INT_MIN;
        int weak = 0;

        for (int i = properties.size() - 1; i >= 0; i--)
        {
            if (properties[i][1] < maxDefense)
                weak++;
            maxDefense = max(maxDefense, properties[i][1]);
        }

        return weak;
    }
};

// stack base approach
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        int n = properties.size();
        sort(properties.begin(), properties.end(), [](auto &a, auto &b)
             { return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0]; });

        stack<int> st; // store only defense
        int weak = 0;

        for (auto &p : properties)
        {
            while (!st.empty() && st.top() < p[1])
            {
                // st.top() is weaker because this 'p' has higher attack (guaranteed by sort) and higher defense
                weak++;
                st.pop();
            }
            st.push(p[1]);
        }

        return weak;
    }
};
