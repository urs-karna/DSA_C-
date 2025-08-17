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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //reverse(postorder.begin(), postorder.end());
        unordered_map<int,int>inMap;

        for(int i=0;i<inorder.size();i++) {
            inMap[inorder[i]]=i;

        }

        TreeNode* root= Construct_Tree(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,inMap);
        return root;
        
    }

    TreeNode* Construct_Tree(vector<int>& postorder,int post_st, int post_end,vector<int>&inorder,int in_st,int in_end,unordered_map<int,int>&inMap)  {

       if(post_st < post_end || in_st > in_end ) return NULL;

        TreeNode* node= new TreeNode(postorder[post_st]);


       int  In_root = inMap[node->val];
       int num_left =  In_root - in_st;
       int num_right=  in_end- In_root;

       node->left= Construct_Tree(postorder, post_st- num_right -1,post_end, inorder, in_st , In_root-1, inMap);

       node->right= Construct_Tree(postorder, post_st-1, post_st-num_right, inorder, In_root+1, in_end, inMap);

       return node;


   }
};