/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
        {
            vector<string> ret;
            return ret;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            vector<string> ret;
            string now = std::to_string(root->val);
            ret.push_back(now);
            return ret;
        }

        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);

        vector<string> ret;
        for(const auto& x : leftPaths)
        {
            string now = std::to_string(root->val) + "->" + x;
            ret.push_back(now);
        }

        for(const auto& x : rightPaths)
        {
            string now = std::to_string(root->val) + "->" + x;
            ret.push_back(now);
        }

        return ret;

    }
};