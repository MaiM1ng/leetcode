class Solution {
public:
    vector<vector<int>> res;

    void dfs(int cur, int n, vector<int>& curSet, vector<int>& nums) {
        res.push_back(curSet);

        for (int i = cur; i < n; i++) {
            // printf("cur = %d fuck %d next = %d\n", i, nums[i]);
            curSet.push_back(nums[i]);
            dfs(i + 1, n, curSet, nums);
            curSet.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> curSet;

        // for (int i = 0; i < n; i++) {
        //     dfs(i, n, curSet, nums);
        // }

        dfs(0, n, curSet, nums);

        return res;
    }
};
