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
    bool find_path(TreeNode* root, TreeNode* key , vector<TreeNode*> &res) {

        if(root == NULL) return false ;
         res.push_back(root);
         if(root->val == key->val ) return true;

         if(find_path(root->left,key,res) || find_path(root->right,key,res) ) return true;
         res.pop_back();
         return false;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       vector<TreeNode*>arr1,arr2;
       find_path(root,p,arr1);
       find_path(root,q,arr2);

       int i=0,j=0;
      TreeNode* dummy = NULL;
       while (i< arr1.size()  && j<arr2.size()) {

        if(arr1[i] == arr2[j]) {

            dummy=arr1[i];
            i++;
            j++;

        } 
        else break;
       }
      
     return dummy;

    }
};