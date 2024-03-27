class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;

    void dfs(vector<int>& nums, vector<int>& sel) {
        int n = nums.size();

        if (sel.size() == n) {
            res.push_back(sel);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                sel.push_back(nums[i]);
                dfs(nums, sel);
                used[i] = false;
                sel.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        used = vector<bool>(n, false);
        vector<int> sel;

        for (int i = 0; i < n; i++) {
            used[i] = true;
            sel.push_back(nums[i]);
            dfs(nums, sel);
            sel.pop_back();
            used[i] = false;
        }

        return res;
    }
};
