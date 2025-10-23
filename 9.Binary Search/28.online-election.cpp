class TopVotedCandidate
{
    vector<int> leaders;
    unordered_map<int, int> mp;
    vector<int> times;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        this->times = times;
        int curLeader = -1;
        int maxfreq = 0;
        for (auto p : persons)
        {
            mp[p]++;
            if (mp[p] >= maxfreq)
            {
                maxfreq = mp[p];
                curLeader = p;
            }
            leaders.push_back(curLeader);
        }
    }

    int q(int t)
    {
        int idx =
            upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */