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
    vector<int> rightSideView(TreeNode* root) {
        
        map<int,TreeNode*>node_list;

        queue<pair<TreeNode*,int>>q;
        vector<int>res;
        if(root==NULL) return res;

        q.push({root,0});
        while(!q.empty()) {

            auto top_ele=q.front();
            q.pop();
            TreeNode* node = top_ele.first;
            int x = top_ele.second;

            node_list[x]=node;

            if(node->left) q.push({node->left,x+1});
            if(node->right) q.push({node->right,x+1});
        } 
        for(auto it : node_list) {
            res.push_back(it.second->val);

        }
        return res;
    }
};