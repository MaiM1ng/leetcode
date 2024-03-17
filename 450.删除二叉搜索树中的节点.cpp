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
    TreeNode* getMax(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        while (root->right) {
            root = root->right;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            } else if (root->left && root->right == NULL) {
                return root->left;
            } else if (root->right && root->left == NULL) {
                return root->right;
            } else {
                TreeNode* max_n = getMax(root->left);
                root->left = deleteNode(root->left, max_n->val);
                max_n->left = root->left;
                max_n->right = root->right;
                root = max_n;
            }
        }

        // 关键是return root
        return root;
    }
};
