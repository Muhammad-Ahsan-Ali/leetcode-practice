class MyCalendarThree
{
    map<int, int> mp;

public:
    MyCalendarThree()
    {
    }

    int book(int startTime, int endTime)
    {

        mp[startTime]++;
        mp[endTime]--;

        int k = 0;

        int open = 0;

        for (auto &it : mp)
            open += it.second, k = max(open, k);

        return k;
    }
};
