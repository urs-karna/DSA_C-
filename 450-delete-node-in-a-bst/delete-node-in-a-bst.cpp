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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
       if(root == NULL) return NULL;

       // check condtion
       if(root->val == key) {
       
          
        return helper(root);
       
       } 

         TreeNode* dummy=root;
       while( root != NULL  ) {
          
          if(key < root->val) {

           if( root->left != NULL && root->left->val== key) {

            root->left = helper(root->left);
           }

            root=root->left;
          }

          else {
            if(root->right != NULL && root->right->val==key) {
                root->right= helper(root->right);
            }
            root=root->right;
          }
 
       }
       return dummy;

    }
       TreeNode* helper(TreeNode * root) {
         if(!root) return NULL;
       if(root->left==NULL) return root->right;
       if(root->right==NULL) return root->left;

       TreeNode* rightNode= root->right;
       TreeNode* leftNode= find_max_node(root->left);

       leftNode->right = rightNode;

       return root->left;


       }
    
      TreeNode*  find_max_node(TreeNode* root) {
          
          if(root->right == NULL) return root;
          return find_max_node(root->right);
       }

    
};