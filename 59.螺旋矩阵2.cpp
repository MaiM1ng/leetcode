class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt = 1;
        int upper = 0;
        int lower = n - 1;
        int left = 0;
        int right = n - 1;

        while (cnt <= n * n) {
            for (int i = left; i <= right; i++) {
                ans[upper][i] = cnt;
                cnt++;
            }
            upper++;
            if (upper > lower) break;

            for (int i = upper; i <= lower; i++) {
                ans[i][right] = cnt;
                cnt++;
            }
            right--;
            if (right < left) break;

            for (int i = right; i >= left; i--) {
                ans[lower][i] = cnt;
                cnt++;
            }
            lower--;
            if (lower < upper) break;

            for (int i = lower; i >= upper; i--) {
                ans[i][left] = cnt;
                cnt++; 
            }
            left++;
            if (left > right) break;
        }

        return ans;
    }
};
