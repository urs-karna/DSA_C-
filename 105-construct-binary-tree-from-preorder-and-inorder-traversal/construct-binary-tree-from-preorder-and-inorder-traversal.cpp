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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;

        for(int i=0;i<inorder.size();i++) {
            inMap[inorder[i]]=i;

        }

        TreeNode* root= Construct_Tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }

   TreeNode* Construct_Tree(vector<int>& preorder,int pre_st, int pre_end,vector<int>&inorder,int in_st,int in_end,unordered_map<int,int>&inMap)  {

       if(pre_st > pre_end || in_st > in_end ) return NULL;

        TreeNode* node= new TreeNode(preorder[pre_st]);


       int  In_root = inMap[node->val];
       int num_left =  In_root - in_st;

       node->left= Construct_Tree(preorder, pre_st + 1,pre_st + num_left, inorder, in_st , In_root-1, inMap);

       node->right= Construct_Tree(preorder, pre_st+num_left +1, pre_end, inorder, In_root+1, in_end, inMap);

       return node;


   }


};