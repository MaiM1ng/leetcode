class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<vector<int>>& graph, int cur, int dest, vector<int>& path) {
        path.push_back(cur);

        if (cur == dest) {
            res.push_back(path);
            path.pop_back();
            return;
        }

        for (int child : graph[cur]) {
            dfs(graph, child, dest, path);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        int n = graph.size();

        dfs(graph, 0, n - 1, path);

        return res;
    }
};
