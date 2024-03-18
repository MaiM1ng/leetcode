class Solution {
public:
    vector<bool> visited;
    vector<int> onPath;
    bool hasCycle;

    void dfs(vector<int> graph[], int cur) {
        if (onPath[cur] == true) {
            hasCycle = true;
        }

        if (visited[cur]) return;

        visited[cur] = true;
        onPath[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++) {
            dfs(graph, graph[cur][i]);
        }
        onPath[cur] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        visited = vector<bool>(numCourses);
        onPath = vector<int>(numCourses);
        hasCycle = false;
 
        // build graph
        for (vector<int> edge: prerequisites) {
            int a = edge[0];
            int b = edge[1];

            graph[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            dfs(graph, i);
        }

        return !hasCycle;
    }
};
