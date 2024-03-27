class Solution {
public:
    vector<vector<int>> res;

    void dfs(int cur, int n, vector<int>& path, int target) {
        if (target == path.size()) {
            res.push_back(path);
            return;
        }

        // res.push_back(cur);

        for (int i = cur; i < n; i++) {
            path.push_back(i + 1);
            dfs(i + 1, n, path, target);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;

        dfs(0, n, path, k);

        return res;
    }
};
