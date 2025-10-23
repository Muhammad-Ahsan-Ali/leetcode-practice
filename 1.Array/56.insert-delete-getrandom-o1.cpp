class RandomizedSet
{
    vector<int> arr;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.contains(val))
            return false;
        arr.push_back(val);

        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!mp.contains(val))
            return false;

        int idx = mp[val];
        int lastElem = arr.back(); // should be before pop
        arr[idx] = lastElem;
        arr.pop_back();
        mp[lastElem] = idx;
        mp.erase(val); // should be at last
        return true;
    }

    int getRandom()
    {
        int n = arr.size();
        int idx = rand() % n;
        return arr[idx];
    }
};