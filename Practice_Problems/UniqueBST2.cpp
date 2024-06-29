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
    map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> generateTrees(int n) {

        return solve(1, n);
    }

    vector<TreeNode*> solve(int st, int ed)
    {
        if(st>ed)
        {
            vector<TreeNode*> ret;
            TreeNode* now = nullptr;
            ret.push_back(now);
            return ret;
        }

        vector<TreeNode*> ans;
        for(int i=st; i<=ed; i++)
        {
            vector<TreeNode*> left = solve(st, i-1);
            vector<TreeNode*> right = solve(i+1, ed);
            for(const auto& x : left)
            {
                for(const auto& y : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};