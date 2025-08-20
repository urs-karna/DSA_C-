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

    void inorder( TreeNode* &root , vector<int> & res){
    if(root==NULL ) return ;

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right,res);
}

void check_swap(TreeNode* &root, int &i,vector<int> & res) {
   if( root == NULL) return;
    check_swap(root->left, i, res);

      if(root->val != res[i]) swap(root->val, res[i]);
      i++;
     check_swap(root->right, i,res);

}
    void recoverTree(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        sort(res.begin(), res.end());
        int i=0;
        check_swap(root,i,res);
        
    }
};