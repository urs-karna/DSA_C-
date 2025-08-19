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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root= new TreeNode(preorder[0]);
        TreeNode* dummy = root;
        for(int i=1;i<preorder.size();i++) {
            insert(root,preorder[i]);
        }

        return dummy;
    }

    void insert(TreeNode* &root, int val) {

         if(root==NULL) {
            root= new TreeNode(val);
            return;
         }
         if(val < root->val) {
          return  insert(root->left,val);
         }
         if(val> root->val) {
           return  insert(root->right,val);
         }

    }
};