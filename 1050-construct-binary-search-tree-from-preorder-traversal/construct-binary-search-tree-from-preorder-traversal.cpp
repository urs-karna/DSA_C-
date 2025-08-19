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
       int i=0;
       
       return ConstructBST(preorder,i,INT_MAX); 
    }

    TreeNode* ConstructBST(vector<int> &preorder,int  &i,int max_val ){

       if( i >= preorder.size() || preorder[i] > max_val ) {
        return NULL;
       }
       TreeNode* node= new TreeNode(preorder[i++]);

      node->left= ConstructBST(preorder,i,node->val);

      node->right= ConstructBST(preorder, i, max_val);
       return node;
    }
};