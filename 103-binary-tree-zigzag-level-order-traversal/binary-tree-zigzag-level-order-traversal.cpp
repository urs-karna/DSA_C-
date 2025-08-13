/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool flag=0;
        queue<TreeNode*> q;

        if (root == NULL)
            return res;
        q.push(root);
        while (!q.empty()) {

            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {

                TreeNode* newNode =q.front();
                 q.pop();
                  level.push_back(newNode->val);
                 
                  if(newNode->left) q.push(newNode->left);
                  if(newNode->right) q.push(newNode->right);
                
            }
           
            
            
            if(flag==0) {
                  res.push_back(level);
                  flag=1;
        }
        else {
            reverse(level.begin(),level.end());
            res.push_back(level);
             flag=0;
        }
        }
        return res; 
        
    }
};