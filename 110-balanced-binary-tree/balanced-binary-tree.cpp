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
    int max_depth(TreeNode* root) {
     if(root==NULL) return 0;
        
       int left=max_depth(root->left);
       int right=max_depth(root->right);
       return 1+max( left,right);

    }
    bool isBalanced(TreeNode* root) {
       if(root==NULL) return true;     

     int lh=max_depth(root->left);
     int rh=max_depth(root->right);

     if(abs(lh-rh) > 1) return false;

     bool left= isBalanced(root->left);
     bool right=isBalanced(root->right);
      if(!left || !right) return false;
     return true;

    }
};