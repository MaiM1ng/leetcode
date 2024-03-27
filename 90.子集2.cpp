class Solution {
public:
    vector<vector<int>> res;

    void dfs(int cur, vector<int>& path, vector<int>& nums) {
        res.push_back(path);

        for (int i = cur; i < nums.size(); i++) {
            if (i != cur && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(i + 1, path, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;

        dfs(0, path, nums);

        return res;
    }
};
