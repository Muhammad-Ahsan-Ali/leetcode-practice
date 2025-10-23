
#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();

        auto allSame = [&](int r, int c, int sz) -> bool
        {
            for (int i = r; i < (r + sz); i++)
                for (int j = c; j < (c + sz); j++)
                    if (grid[i][j] != grid[r][c])
                        return false;
            return true;
        };

        auto build = [&](auto &&build, int i, int j, int sz) -> Node *
        {
            if (sz == 1 || allSame(i, j, sz))
            {
                Node *node = new Node(grid[i][j], true);
                return node;
            }

            int subSz = sz / 2;
            Node *node = new Node(grid[i][j], false);
            node->topLeft = build(build, i, j, subSz);
            node->bottomLeft = build(build, i + subSz, j, subSz);
            node->topRight = build(build, i, j + subSz, subSz);
            node->bottomRight = build(build, i + subSz, j + subSz, subSz);
            return node;
        };

        Node *root = build(build, 0, 0, n);

        return root;
    }
};