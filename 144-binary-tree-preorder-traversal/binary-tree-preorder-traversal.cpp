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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL)
            return res;

        st.push(root);

        while (!st.empty()) {

            TreeNode* newNode = st.top();
            st.pop();
            res.push_back(newNode->val);

            // Lifo
            if (newNode->right)
                st.push(newNode->right);
            if (newNode->left)
                st.push(newNode->left);
        }

        return res;
    }
};