class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto &arr = mp[key];
        int idx = upper_bound(arr.begin(), arr.end(), timestamp,
                              [](int b, const pair<int, string> &a)
                              {
                                  return b < a.first;
                              }) -
                  arr.begin() - 1;
        if (idx < 0)
            return "";

        return arr[idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */