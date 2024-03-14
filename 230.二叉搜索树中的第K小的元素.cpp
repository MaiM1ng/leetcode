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
    int rk = 0;
    int target;
    int ans;

    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        traverse(root->left);
        rk++;
        if (rk == target) {
            ans = root->val;
        }
        traverse(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        target = k;
        traverse(root);
        return ans;
    }
};
