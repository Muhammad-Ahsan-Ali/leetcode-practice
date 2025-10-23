class MyCalendar
{
private:
    set<pair<int, int>> st;

public:
    MyCalendar()
    {
    }

    bool book(int startTime, int endTime)
    {
        if (st.empty())
        {
            st.insert({startTime, endTime});
            return true;
        }

        auto it = lower_bound({startTime, endTime});

        if (it.second <)
    }
};
