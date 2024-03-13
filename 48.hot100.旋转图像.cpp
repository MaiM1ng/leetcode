class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // 先转置： 与主对角线 稍微简单一点
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix[i].size(); j++) {
                if (i == j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};
