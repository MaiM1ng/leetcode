class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int cur_col = n - 1;
        int cur_row = 0;

        while (cur_row < m && cur_col >= 0) {
            if (matrix[cur_row][cur_col] > target) {
                cur_col--;
            } else if (matrix[cur_row][cur_col] < target) {
                cur_row++;
            } else {
                return true;
            }
        }

        return false;
    }
};
