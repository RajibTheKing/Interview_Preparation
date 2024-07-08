/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }

    TreeNode* decode(int& pos, vector<string>& nodes)
    {
        if (pos == nodes.size())
        {
            return nullptr;
        }

        if (nodes[pos] == "N")
        {
            pos++;
            return nullptr;
        }

        TreeNode* now = new TreeNode(stoi(nodes[pos]));
        pos++;
        TreeNode* leftAns = decode(pos, nodes);
        TreeNode* rightAns = decode(pos, nodes);

        now->left = leftAns;
        now->right = rightAns;

        return now;
    }

    string encode(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "N";
        }

        string now = to_string(root->val);
        string leftStr = encode(root->left);
        string rightStr = encode(root->right);

        return now + " " + leftStr + " " + rightStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> splittedData;
        string s;
        char delimiter = ' ';
        while(getline(ss, s, delimiter))
        {
            splittedData.push_back(s);
        }
        int pos = 0;
        return decode(pos, splittedData);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//"(  ((null)(2)(null))  (1)  (null)(4)(null)(3)(5))"