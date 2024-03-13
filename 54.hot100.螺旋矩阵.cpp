class Solution {
public:
    // → ↓ ← ↑ 一循环
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        int upper = 0;
        int lower = m - 1;
        int left = 0;
        int right = n - 1;

        while (res.size() < m * n) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[upper][i]);
            }
            upper++;
            if (upper > lower) break;

            for (int i = upper; i <= lower; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (left > right) break;

            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[lower][i]);
                res.push_back(matrix[lower][i]);
            }
            lower--;
            if (lower < upper) break;

            for (int i = lower; i >= upper; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
            if (left > right) break;
        }

        return res;
    }
};
