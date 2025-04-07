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

    void increasePrefix() { cntPrefix++; }

    int getEndCnt() { return cntEndWith; }

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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
