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
     
     int max_depth(TreeNode* root,int & maxi ) 
      {
    
       if(root==NULL) return 0;

       int left= max_depth(root->left,maxi);
       int right = max_depth(root->right,maxi);
        maxi = max(maxi,left+right);
       return 1+max(left,right);

      }     
    int diameterOfBinaryTree(TreeNode* root) {
         
        int maxi=0;
        int height=max_depth(root,maxi);
          return maxi;


    }
};