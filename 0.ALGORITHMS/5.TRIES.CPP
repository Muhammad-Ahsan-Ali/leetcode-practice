
// FOR MAX XOR ....................................................

struct Node
{
    Node *links[2];
    int max_ind;
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

    void insert(ll num, ll ind)
    {
        Node *node = root;
        node->max_ind = ind;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->max_ind = ind;
        }
    }

    ll getMax(ll num, ll l)
    {
        ll max = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containKey(1 - bit) && node->get(1 - bit)->max_ind >= l)
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

// FOR PREFIX EQUAL STRING

struct Node
{
    Node *links[26];
    bool flag = false;
    int cntEndWith = 0;
    int cntPrefix = 0;

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
    }

    bool containKey(char c) { return (links[c - 'a'] != nullptr); }

    void put(char c, Node *node) { links[c - 'a'] = node; }

    Node *get(char c) { return links[c - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }

    void increaseEnd() { cntEndWith++; }

    int getEndCnt() { return cntEndWith; }

    void increasePrefix() { cntPrefix++; }

    int getPrefixCnt() { return cntPrefix; }

    void reduceEndCnt() { cntEndWith--; }

    void reducePrefixCnt() { cntPrefix--; }
};

class Trie
{
private:
    Node *root;
    void deleteTrie(Node *node)
    {
        if (!node)
            return;
        for (int i = 0; i < 26; i++)
        {
            if (node->links[i])
            {
                deleteTrie(node->links[i]);
            }
        }
        delete node;
    }

public:
    Trie() { root = new Node; }
    ~Trie() { deleteTrie(root); }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node);
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->setEnd();
        node->increaseEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEndCnt();
    }

    int countWordsStartingWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->getPrefixCnt();
    }

    void erase(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return;
            }
            node = node->get(word[i]);
            node->reducePrefixCnt();
        }
        node->reduceEndCnt();
    }

    string longestCommonPrefix(string word, int n)
    {
        string str = "";
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            node = node->get(word[i]);
            if (node->getPrefixCnt() != n)
            {
                return str;
            }

            str.push_back(word[i]);
        }
        return str;
    }

    bool checkIfAllPrefixExists(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
            if (!node->isEnd())
            {
                return false;
            }
        }
        return true;
    }
};
