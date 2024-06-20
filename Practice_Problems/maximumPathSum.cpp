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
    //unordered_map<TreeNode*, int> maxVal;
    int result;
    int maxPathSum(TreeNode* root)
    {
        if ( root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right== nullptr)
        {
            return root->val;
        }

        result = INT_MIN;
        solve(root);
        return result;
    }

    int solve(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftMax = solve(node->left);
        int rightMax = solve(node->right);
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        // update each time we have current maximum
        result = max(result, node->val+leftMax + rightMax);

        return max(leftMax, rightMax) + node->val;
    }
};