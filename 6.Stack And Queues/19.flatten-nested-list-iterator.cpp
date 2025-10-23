class NestedIterator
{
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            st.push(nestedList[i]);
        }
    }

    int next()
    {
        int next = st.top().getInteger();
        st.pop();
        return next;
    }

    bool hasNext()
    {

        while (!st.empty())
        {
            if (st.top().isInteger())
            {
                return true;
            }
            vector<NestedInteger> nestedList = st.top().getList();
            st.pop();
            for (int i = nestedList.size() - 1; i >= 0; i--)
            {
                st.push(nestedList[i]);
            }
        }
        return false;
    }
};
