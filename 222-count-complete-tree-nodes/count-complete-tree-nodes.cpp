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
    void no_of_nodes(TreeNode* root,int &cnt) {
           if(root==NULL) return;

           if(root->left){
            cnt++;
             no_of_nodes(root->left,cnt);
           }
            if(root->right){
            cnt++;
             no_of_nodes(root->right,cnt);
           }

    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
      //  if(root) return 1;

        int cnt=0;
        no_of_nodes(root,cnt);
        return cnt+1;
        
    }
};