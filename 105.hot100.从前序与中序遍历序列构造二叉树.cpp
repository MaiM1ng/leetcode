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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (size == 0) {
            return NULL;
        }

        vector<int> left_pre;
        vector<int> right_pre;
        vector<int> left_in;
        vector<int> right_in;
        int left_len;
        int right_len;
        int root_idx = -1;
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 0; i < size; i++) {
            if (inorder[i] == preorder[0]) {
                root_idx = i;
                break;
            }
        }

        left_len = root_idx;
        right_len = size - left_len - 1;

        left_pre = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + left_len);
        left_in = vector<int>(inorder.begin(), inorder.begin() + left_len);
        right_pre = vector<int>(preorder.begin() + 1 + left_len, preorder.end());
        right_in = vector<int>(inorder.begin() + root_idx + 1, inorder.end());

        root->left = buildTree(left_pre, left_in);
        root->right = buildTree(right_pre, right_in);

        return root;
    }
};
