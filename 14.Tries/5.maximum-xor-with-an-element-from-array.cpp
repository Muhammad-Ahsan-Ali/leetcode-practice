class Solution
{

private:
    struct Node
    {
        Node *links[2];

        Node()
        {
            for (int i = 0; i < 2; i++)
            {
                links[i] = nullptr;
            }
        }

        bool containKey(int bit) { return (links[bit] != nullptr); }

        void put(int bit, Node *node) { links[bit] = node; }

        Node *get(int bit) { return links[bit]; }
    };

    class Trie
    {
    private:
        Node *root;

    public:
        Trie() { root = new Node; }

        void insert(int num)
        {
            Node *node = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1;
                if (!node->containKey(bit))
                {
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMax(int num)
        {
            int max = 0;
            Node *node = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1;
                if (node->containKey(1 - bit))
                {
                    node = node->get(1 - bit);
                    max = max | (1 << i);
                }
                else
                {
                    node = node->get(bit);
                }
            }
            return max;
        }
    };

public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        vector<int> output(m, -1);

        vector<pair<int, pair<int, int>>> oq;

        for (int i = 0; i < m; i++)
        {
            oq.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(nums.begin(), nums.end());
        sort(oq.begin(), oq.end());

        int i = 0;
        int j = 0;
        Trie trie;

        while (j < m)
        {
            while (i < n && nums[i] <= oq[j].first)
            {
                trie.insert(nums[i]);
                i++;
            }
            if (i > 0)
            {
                output[oq[j].second.second] = trie.getMax(oq[j].second.first);
            }
            j++;
        }
        return output;
    }
};
