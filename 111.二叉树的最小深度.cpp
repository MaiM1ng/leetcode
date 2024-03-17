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
    int minDep = INT_MAX;

    void helper(TreeNode* root, int dep) {
        if (root == NULL) {
            return;
        }

        helper(root->left, dep + 1);
        helper(root->right, dep + 1);

        if (root->left == NULL && root->right == NULL) {
            minDep = min(minDep, dep);
        } 
    }

    int minDepth(TreeNode* root) {
        helper(root, 0);
        return minDep == INT_MAX ? 0 : minDep + 1;
    }
};
