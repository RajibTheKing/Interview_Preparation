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
    map<TreeNode*, int> mp;

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
        {
            return true;
        }

        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if(max(leftDepth, rightDepth) - min(leftDepth, rightDepth) <= 1)
        {
            return isBalanced(root->left) & isBalanced(root->right);
        }
        else
            return false;
    }

    int getDepth(TreeNode* now)
    {
        if (now == nullptr)
        {
            return 0;
        }

        if(mp.find(now) != mp.end())
        {
            return mp[now];
        }

        int ans = 0;
        ans = max(ans, 1 + getDepth(now->left));
        ans = max(ans, 1 + getDepth(now->right));

        mp[now] = ans;
        return ans;
    }
};