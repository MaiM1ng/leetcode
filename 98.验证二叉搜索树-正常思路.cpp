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

    bool tra(TreeNode* root, TreeNode* minv, TreeNode* maxv) {
        if (root == NULL) {
            return true;
        }

        if (minv && minv->val >= root->val) {
            return false;
        }

        if (maxv && maxv->val <= root->val) {
            return false;
        }

        bool left = tra(root->left, minv, root);
        bool right = tra(root->right, root, maxv);

        return left && right;
    }   

    bool isValidBST(TreeNode* root) {
        return tra(root, NULL, NULL);
    }
};
