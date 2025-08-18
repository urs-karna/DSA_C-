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
    int val=-1;
     void inorder(TreeNode* root, int &idx,int k) {

        if(root==NULL) return ;
       
       if(root->left)  inorder(root->left,idx,k);
         
         idx++;
         if(idx==k) { 
          val= root->val;
         cout<<root->val; 
        }
       if(root->right)  inorder(root->right,idx,k);
       
        
     }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int idx=0;
        inorder(root,idx,k);
         return val;

    }
};