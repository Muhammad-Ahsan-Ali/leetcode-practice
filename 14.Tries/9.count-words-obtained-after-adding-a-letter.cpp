struct Node
{
    Node *links[26];
    int endCount = 0; // number of target words ending here

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
    }

    bool containsKey(char c) { return (links[c - 'a'] != nullptr); }
    void put(char c, Node *node) { links[c - 'a'] = node; }
    Node *get(char c) { return links[c - 'a']; }

    // increment count for each inserted target word that ends here
    void setEnd() { endCount++; }

    // check whether there is at least one target word ending here
    bool isEnd() { return endCount > 0; }

    // consume one occurrence (decrement). Keeps duplicates correctly handled.
    void unsetEnd()
    {
        if (endCount > 0)
            endCount--;
    }
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
                deleteTrie(node->links[i]);
        }
        delete node;
    }

public:
    Trie() { root = new Node; }
    ~Trie() { deleteTrie(root); }

    void insert(string word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
            {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    // Minimal change: recursive DFS that tries both matching and inserting.
    bool search(string &word, int idx, Node *node, bool usedExtra = false)
    {
        if (!node)
            node = root;
        int n = (int)word.size();

        // If we've consumed the whole start-word:
        if (idx == n)
        {
            if (usedExtra)
            {
                // extra letter was already used earlier -> accept only if this
                // node ends a target
                if (node->isEnd())
                {
                    node->unsetEnd();
                    return true;
                }
                return false;
            }
            else
            {
                // extra letter not used yet -> it must be appended now: check
                // terminal children
                for (int k = 0; k < 26; ++k)
                {
                    if (node->links[k] && node->links[k]->isEnd())
                    {
                        node->links[k]->unsetEnd();
                        return true;
                    }
                }
                return false;
            }
        }

        char c = word[idx];

        // Option 1: match the current char if possible
        if (node->containsKey(c))
        {
            if (search(word, idx + 1, node->get(c), usedExtra))
                return true;
        }

        // Option 2: if we haven't used the extra letter yet, try inserting any
        // child here
        if (!usedExtra)
        {
            for (int k = 0; k < 26; ++k)
            {
                if (node->links[k])
                {
                    char ch = 'a' + k;
                    if (ch == c)
                        continue; // already tried matching c above
                    if (search(word, idx, node->links[k], true))
                        return true;
                }
            }
        }

        return false;
    }
};

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        Trie trie;

        for (string &word : targetWords)
        {
            sort(word.begin(), word.end());
            trie.insert(word);
        }

        int cnt = 0;

        // Search each startWord (after sorting)
        // Keep calling search repeatedly because one start can produce multiple
        // targets. Each successful search will unset that target in the trie so
        // it won't be counted again.
        for (string &word : startWords)
        {
            sort(word.begin(), word.end());
            while (trie.search(word, 0, nullptr))
            {
                ++cnt;
            }
        }

        return cnt;
    }
};

// optimal  solution


class Solution
{
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<string> startSet;

        for (string word : startWords)
        {
            sort(word.begin(), word.end());
            startSet.insert(word);
        }

        int count = 0;

        for (string word : targetWords)
        {
            sort(word.begin(), word.end());
            for (int i = 0; i < word.size(); i++)
            {
                string temp = word;
                temp.erase(temp.begin() + i);
                if (startSet.count(temp))
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};