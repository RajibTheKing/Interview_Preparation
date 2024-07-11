/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if (root == nullptr)
        {
            return false;
        }
        
        if (root->left == nullptr && root->right == nullptr)
        {
            if (target == root->data)
                return true;
            else
                return false;
        }
        
        return hasPathSum(root->left, target - root->data) |  hasPathSum(root->right, target - root->data);
    }
};


//         1

//   2         3
   
//  N   N    4      6
         
//         n    5   N   N
        
//             7   N
            
//          N    N