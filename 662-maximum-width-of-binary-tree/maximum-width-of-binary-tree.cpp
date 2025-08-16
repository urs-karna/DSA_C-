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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long >>q;
        if(root==NULL) return 0;
        q.push({root,0});
        int width=1;
        while(!q.empty()) {
           
           int n=q.size();

           long long  min_idx=q.front().second;
            long long  first,last;
           for(int i=0;i<n;i++) {
             
             auto top_ele=q.front();
             TreeNode* node=top_ele.first;
             long long  curr_idx= top_ele.second - min_idx;
             q.pop();

             if(i==0) first=curr_idx;
             if(i==n-1) last=curr_idx;

             if(node->left) q.push({node->left,curr_idx*2+1});
             if(node->right) q.push({node->right,curr_idx*2+2});


           }
           width= max(width, (int)(last-first+1));


        }
        return width;
    }
};