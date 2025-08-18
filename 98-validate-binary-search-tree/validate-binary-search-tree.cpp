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
    bool isValidBST(TreeNode* root) {
         
         return check_BST(root, LONG_MIN , LONG_MAX);

    }
    bool check_BST(TreeNode* &root,long min_val , long max_val) {

        if(root==NULL) return true;

        if( root->val >= max_val || root->val <= min_val) return false;
        return check_BST(root->left, min_val, root->val)&& check_BST(root->right, root->val, max_val );


    }
};