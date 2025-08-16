/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track ) {
      if(root==NULL )return;

      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
          TreeNode* node=q.front();
          q.pop();

          if(node->left) {
          parent_track[node->left]=node;
           q.push(node->left);

          }

          if(node->right) {
             parent_track[node->right]= node;
           q.push(node->right);
          }

      }


   }
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
       vector<int> res;
       if (root==NULL) return res;
        parent(root,parent_track);

        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool> visted;

        q.push(target);
        visted[target] = true;
         int dist=0;
        while(!q.empty()) {
        int n=q.size();
        if(dist==k) break;
         dist++;

         for(int i=0;i<n;i++) {

            TreeNode* node= q.front();
            q.pop();
            if(node->left && !visted[node->left]) {
                q.push(node->left);
                visted[node->left] = true;

            }

            if(node->right && !visted[node->right]) {
                q.push(node->right);
                visted[node->right] = true;
            }

            if(parent_track[node] && !visted[parent_track[node]]) {
                q.push(parent_track[node]);
                visted[parent_track[node]]= true;
            }
         }


        }
        
       while(!q.empty()) {
         TreeNode* node=q.front();
         q.pop();
        res.push_back(node->val);
       }
       return res;

    }
};