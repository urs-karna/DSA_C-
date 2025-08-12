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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;

        if(root == NULL) return 0;
        q.push(root);
        int cnt=0;

        while(!q.empty()){

            cnt++;
        int n=q.size();

        for(int i=0;i<n;i++) { 
            TreeNode* newNode = q.front();
            q.pop();
            if(newNode->left) q.push(newNode->left);
            if(newNode->right) q.push(newNode->right);

        }

        }
        return cnt;
       
    }
};