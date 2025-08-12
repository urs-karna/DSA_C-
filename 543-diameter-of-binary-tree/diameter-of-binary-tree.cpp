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
     
     int max_depth(TreeNode* root )
      {
    
       if(root==NULL) return 0;

       int left= max_depth(root->left);
       int right = max_depth(root->right);

       return 1+max(left,right);


      }     
    int diameterOfBinaryTree(TreeNode* root) {
         
         if(root==NULL) return 0;
         int LH = max_depth(root->left);

         int RH= max_depth(root->right);
          int through_root= LH + RH;

          int left=diameterOfBinaryTree(root->left);
          int right=diameterOfBinaryTree(root->right);
          return max(through_root,max(left,right));


    }
};