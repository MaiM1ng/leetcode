class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1));
        
        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            graph[a][b] = 1;
        }

        for (int i = 1; i <= n; i++) {
            bool isJudge = true;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (graph[j][i] == 1 && graph[i][j] == 0) {
                    continue;
                } else {
                    isJudge = false;
                    break;
                }
            }
            if (isJudge) return i;
        }

        return -1;
    }
};
