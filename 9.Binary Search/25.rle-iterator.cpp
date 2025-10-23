class RLEIterator
{
    vector<pair<long long, int>> prefix;
    long long covered = 0;
    int covered_ind = 0;

public:
    RLEIterator(vector<int> &encoding)
    {
        long long total = 0;
        for (int i = 0; i < encoding.size(); i += 2)
        {
            int count = encoding[i];
            int value = encoding[i + 1];
            total += count;
            prefix.push_back({total, value});
        }
    }

    int next(int n)
    {
        covered += n;

        int ind = lower_bound(prefix.begin() + covered_ind, prefix.end(), covered,
                              [](const pair<long long, int> &p, long long val)
                              { return p.first < val; }) -
                  prefix.begin();
        covered_ind = ind;
        return covered_ind < prefix.size() ? prefix[ind].second : -1;
    }
};
