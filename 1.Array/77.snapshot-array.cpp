class SnapshotArray
{
    vector<vector<pair<int, int>>> idxUpdates;
    int snapShot;

public:
    SnapshotArray(int length)
    {
        idxUpdates.resize(length);
        for (int i = 0; i < length; i++)
            idxUpdates[i].push_back({0, 0});
        snapShot = 0;
    }

    void set(int index, int val)
    {
        idxUpdates[index].push_back({snapShot, val});
    }

    int snap() { return snapShot++; }

    int get(int index, int snap_id)
    {

        auto &arr = idxUpdates[index];
        auto it = upper_bound(begin(arr), end(arr), make_pair(snap_id, INT_MAX));

        return prev(it)->second;
    }
};
