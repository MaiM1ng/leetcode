class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i] = vector<int>(i + 1, 0);
            ans[i][0] = 1;
            ans[i][i] = 1;
        }

        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < ans[i].size(); j++) {
                if (ans[i][j] == 0) {
                    ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
                }
            }
        }

        return ans;
    }
};
