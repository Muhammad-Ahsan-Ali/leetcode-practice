class Codec
{
public:
    // Serialize a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null"; // If the tree is empty, return "null"

        string result;
        queue<TreeNode *> q;
        q.push(root); // Start BFS traversal

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                result += to_string(node->val) + ","; // Store the node value
                q.push(node->left);                   // Push left child to queue
                q.push(node->right);                  // Push right child to queue
            }
            else
            {
                result += "null,"; // If null, store "null" in the string
            }
        }

        // Remove trailing comma and return the result
        result.pop_back();
        return result;
    }

    // Deserialize a string to reconstruct the tree.
    TreeNode *deserialize(string data)
    {

        if (data == "null")
            return nullptr; // If input is "null", return empty tree

        // Split the input string into a vector of node values
        vector<string> nodes;
        string temp;

        for (char c : data)
        {
            if (c == ',')
            {
                nodes.push_back(temp); // Store node value in vector
                temp.clear();
            }
            else
            {
                temp.push_back(c);
            }
        }

        if (!temp.empty())
            nodes.push_back(temp); // Add last element to vector

        // Create the root node using the first value in the vector
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> q;
        q.push(root); // Start BFS reconstruction

        int i = 1; // Index to track position in nodes vector
        while (!q.empty() && i < nodes.size())
        {
            TreeNode *parent = q.front();
            q.pop();

            // Process the left child
            if (nodes[i] != "null") // If the left child exists
            {
                TreeNode *leftNode = new TreeNode(stoi(nodes[i]));
                parent->left = leftNode; // Attach left node
                q.push(leftNode);        // Push it into the queue
            }

            i++;

            // Process the right child
            if (i < nodes.size() && nodes[i] != "null") // If the right child exists
            {
                TreeNode *rightNode = new TreeNode(stoi(nodes[i]));
                parent->right = rightNode; // Attach right node
                q.push(rightNode);         // Push it into the queue
            }
            i++;
        }

        return root; // Return the reconstructed tree
    }
};

// Your Codec object will be instantiated and called as such:

// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
