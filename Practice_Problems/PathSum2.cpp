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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        if (root != nullptr)
        {
            vector<int> current;
            ans =  solve(root, current, 0, targetSum);
        }
        return ans;
    }

    vector<vector<int>> solve(TreeNode* node, vector<int> current, int currentSum, int targetSum)
    {
        // base condition
        if (node->left == nullptr && node->right == nullptr)
        {
            //it's a leaf node
            currentSum = currentSum + node->val;
            vector<vector<int>> ans;

            if(currentSum == targetSum)
            {
                current.push_back(node->val);
                ans.push_back(current);
            }
            return ans;
        }

        currentSum += node->val;
        current.push_back(node->val);
        vector<vector<int>> leftBranch;
        if(node->left != nullptr)
            leftBranch = solve(node->left, current, currentSum, targetSum);

        vector<vector<int>> rightBranch;
        if(node->right != nullptr)
            rightBranch = solve(node->right, current, currentSum, targetSum);

        //merge this two vector
        vector<vector<int>> ans;
        std::copy(leftBranch.begin(), leftBranch.end(), std::back_inserter(ans));
        std::copy(rightBranch.begin(), rightBranch.end(), std::back_inserter(ans));
        return ans;
    }
};