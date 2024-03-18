class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1));
        
        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            graph[a][b] = 1;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while (q.size() >= 2) {
            int cand1 = q.front();
            q.pop();
            int cand2 = q.front();
            q.pop();
            if (graph[cand1][cand2] == 1 && graph[cand2][cand1] == 0) {
                q.push(cand2);
            } else if (graph[cand2][cand1] == 1 && graph[cand1][cand2] == 0) {
                q.push(cand1);
            }
        }

        if (q.size() == 0) {
            return -1;
        }

        int cand = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (cand == i) continue;
            if (graph[i][cand] == 0 || graph[cand][i] == 1) {
                return -1;
            }
        }

        return cand;
    }
};
