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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int,map<int,multiset<int>>>node_list;

     queue<pair<TreeNode*,pair<int,int>>>q;
      vector<vector<int>>res;
     if(root==NULL)  return res;
     q.push({root,{0,0}});

     while(!q.empty()) {

    auto top_ele=q.front();
    q.pop();
    TreeNode* node=top_ele.first;
    int x = top_ele.second.first;
    int y = top_ele.second.second;
     
     node_list[x][y].insert(node->val);

     if(node->left) {
        q.push({node->left,{x-1,y+1}});
     }
     if(node->right) {
        q.push({node->right,{x+1,y+1}});
     }

     }

     for( auto p : node_list)  {

        vector<int>col;

        for( auto q : p.second ) {
           
           col.insert(col.end(),q.second.begin(),q.second.end());

        }
        res.push_back(col);
     }
     return res;

    }
};