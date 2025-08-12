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
    int max_depth_sum(TreeNode* root, int& maxi) {
        if (root == NULL)
            return 0;

        int left_sum = max(0, max_depth_sum(root->left, maxi));

        int right_sum = max(0, max_depth_sum(root->right, maxi));

        maxi = max(maxi, root->val + left_sum + right_sum);
        return root->val + max(left_sum, right_sum);
    }

    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxi = INT_MIN;
        int max_sum = max_depth_sum(root, maxi);

        return maxi;
    }
    };