class MyCalendarTwo
{
private:
    set<pair<int, int>> doubleOverlapped;
    vector<pair<int, int>> bookings;

    bool isOverlap(int start1, int end1, int start2, int end2)
    {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> getOverlapRegion(int start1, int end1, int start2,
                                    int end2)
    {
        return {max(start1, start2), min(end1, end2)};
    }

    bool checkTripleOverlap(int startTime, int endTime)
    {

        auto it = doubleOverlapped.lower_bound({startTime, endTime});

        if (it != doubleOverlapped.end() && it->first < endTime)
            return true;

        if (it != doubleOverlapped.begin())
        {
            --it;
            if (it->second > startTime)
                return true;
        }

        return false;
    }

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime)
    {

        if (checkTripleOverlap(startTime, endTime))
        {
            return false;
        }

        for (auto booking : bookings)
        {
            if (isOverlap(booking.first, booking.second, startTime, endTime))
                doubleOverlapped.insert(getOverlapRegion(
                    booking.first, booking.second, startTime, endTime));
        }
        bookings.push_back({startTime, endTime});

        return true;
    }
};
//

class MyCalendarTwo
{
    map<int, int> timeline; // key = time, value = change (+1 start, -1 end)

public:
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        // add the changes tentatively
        timeline[start]++;
        timeline[end]--;

        int active = 0;
        for (auto &p : timeline)
        {
            active += p.second;
            if (active >= 3)
            {
                // rollback since it caused triple booking
                timeline[start]--;
                if (timeline[start] == 0)
                    timeline.erase(start);
                timeline[end]++;
                if (timeline[end] == 0)
                    timeline.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
