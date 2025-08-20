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
    void add_stack_asc(TreeNode* root, stack<TreeNode*>&st1) {
        while(root) {
            st1.push(root);
            root=root->left;
        }
    }
    void add_stack_desc(TreeNode* root, stack<TreeNode*>&st2) {
        while(root) {
            st2.push(root);
            root=root->right;
        }
    }



    bool findTarget(TreeNode* root, int k) {
        if(root->left ==NULL && root->right==NULL) return 0;
        stack<TreeNode*>st1,st2;
        add_stack_asc(root,st1);
        add_stack_desc(root,st2);
        while((!st1.empty()&& !st2.empty())  && st1.top() != st2.top()) {
           TreeNode* st1_top=st1.top();
           TreeNode* st2_top = st2.top();
           int sum= st1_top->val + st2_top->val;
           if(sum==k) return true;

           else if(sum > k) {
            st2.pop();
            if(st2_top->left) add_stack_desc(st2_top->left,st2);
           }
           else {
            st1.pop();
            if(st1_top->right) add_stack_asc(st1_top->right,st1);
           }

        }
        return false ;
    }
};