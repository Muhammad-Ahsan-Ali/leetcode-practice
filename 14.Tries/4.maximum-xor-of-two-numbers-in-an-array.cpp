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
    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        int maxi = 0;
        Trie trie;
        trie.insert(nums[0]);
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, trie.getMax(nums[i]));
            trie.insert(nums[i]);
        }
        return maxi;
    }
};