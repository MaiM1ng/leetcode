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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        int root_val = -1;
        int idx;

        for (int i = 0; i < nums.size(); i++) {
            if (root_val < nums[i]) {
                root_val = nums[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(root_val);
        vector<int> left(nums.begin(), nums.begin() + idx);
        vector<int> right(nums.begin() + idx + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};
