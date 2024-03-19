class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int cnt = 0;

        for (vector<int> edge: prerequisites) {
            int a = edge[0];
            int b = edge[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            cnt++;
            int cur = q.front();
            q.pop();

            for (int child: graph[cur]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return cnt == numCourses;
    }
};
