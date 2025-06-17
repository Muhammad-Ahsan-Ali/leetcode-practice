struct Node
{
    Node *links[26];
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
};

int countDistinctSubstring(string s)
{
    int cnt = 1;
    int n = s.length();
    Node *root = new Node;

    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containKey(s[j]))
            {
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }

    return cnt;
}

// opitimized space using map

struct Node
{
    unordered_map<char, Node *> links;
    bool flag = false;
};

int countDistinctSubstring(string s)
{
    int cnt = 1;
    int n = s.length();
    Node *root = new Node();

    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (node->links.find(s[j]) == node->links.end())
            {
                node->links[s[j]] = new Node();
                cnt++;
            }
            node = node->links[s[j]];
        }
    }

    return cnt;
}