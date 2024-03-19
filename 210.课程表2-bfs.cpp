class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;

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
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int child: graph[cur]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int> {};
    }
};
