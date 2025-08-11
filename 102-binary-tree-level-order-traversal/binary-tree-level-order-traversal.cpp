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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>res;

        queue<TreeNode*>q;
        if(root==NULL) return res;
        q.push(root);
        while( !q.empty()) {
            vector<int>level;
             int n=q.size();
             for(int i=0;i<n;i++) {

             TreeNode* newNode = q.front();
             q.pop();
             level.push_back(newNode->val);

             if(newNode->left) q.push(newNode->left);
             if(newNode->right) q.push(newNode-> right);


             }
             res.push_back(level);
             
        }
        return res;
        
    }
};