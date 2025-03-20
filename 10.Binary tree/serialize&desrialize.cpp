

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Codec {
public:
    // Serialize a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        // Remove trailing comma and return the result
        result.pop_back();
        return result;
    }

    // Deserialize a string to reconstruct the tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        // Split the input string into a vector of node values
        vector<string> nodes;
        string temp;
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(c);
            }
        }
        if (!temp.empty()) nodes.push_back(temp);

        // Create the root node
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* parent = q.front();
            q.pop();

            // Process the left child
            if (nodes[i] != "null") {
                TreeNode* leftNode = new TreeNode(stoi(nodes[i]));
                parent->left = leftNode;
                q.push(leftNode);
            }
            i++;

            // Process the right child
            if (i < nodes.size() && nodes[i] != "null") {
                TreeNode* rightNode = new TreeNode(stoi(nodes[i]));
                parent->right = rightNode;
                q.push(rightNode);
            }
            i++;
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:

// Codec ser, deser;

// TreeNode* ans = deser.deserialize(ser.serialize(root));



    int main()
    {

        return 0;
    }