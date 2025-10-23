struct Node
{
    Node *links[26];
    bool flag = false;

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
    }

    bool conatianKey(char c) { return (links[c - 'a'] != nullptr); }

    void put(char c, Node *node) { links[c - 'a'] = node; }

    Node *get(char c) { return links[c - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
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
            if (!node->conatianKey(word[i]))
            {
                Node *newNode = new Node;
                node->put(word[i], newNode);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word, int idx, Node *node)
    {
        if (!node)
            node = root;

        for (int i = idx; i < word.length(); i++)
        {
            char c = word[i];

            if (c == '.')
            {
                // Try all possible children
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (node->conatianKey(ch))
                    {
                        if (search(word, i + 1, node->get(ch)))
                            return true;
                    }
                }
                return false;
            }
            else
            {
                if (!node->conatianKey(c))
                    return false;
                node = node->get(c);
            }
        }

        return node->isEnd();
    }
};

class WordDictionary
{
    Trie trie;

public:
    WordDictionary() {}

    void addWord(string word) { trie.insert(word); }

    bool search(string word) { return trie.search(word, 0, nullptr); }
};
