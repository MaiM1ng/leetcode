class Solution {
public:
    vector<int> onPath;
    vector<bool> visited;
    vector<int> ans;
    bool hasCycle = false;

    void dfs(vector<int> graph[], int cur) {
        
        if (onPath[cur] == 1) {
            // ans.clear();
            hasCycle = true;
        }

        if (hasCycle || visited[cur]) {
            return;
        }

        onPath[cur] = 1;
        visited[cur] = true;

        for (int child: graph[cur]) {
            dfs(graph, child);
        }
        ans.push_back(cur);

        onPath[cur] = 0;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        onPath = vector<int>(numCourses);
        visited = vector<bool>(numCourses);
        vector<int> graph[numCourses];

        // build graph
        for (vector<int> edge : prerequisites) {
            int from = edge[0];
            int to = edge[1];

            graph[to].push_back(from);
        }

        for (int i = 0; i < numCourses; i++) {
            dfs(graph, i);
            // if (hasCycle) return ans;
        }

        if (hasCycle) {
            ans.clear();
        } else {
            reverse(ans.begin(), ans.end()); 
        }

        return ans;
    }
};
