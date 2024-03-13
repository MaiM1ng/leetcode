class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        vector<int> ans(1001);
        
        for (auto each : trips) {
            int numPass = each[0];
            int from = each[1];
            int to = each[2];
            diff[from] += numPass;
            // to - 1了 因为to站要下车了
            diff[to] -= numPass;
        }

        ans[0] = diff[0];
        if (ans[0] > capacity) {
            return false;
        }
        for (int i = 1; i <= 1000; i++) {
            ans[i] = ans[i - 1] + diff[i];
            if (ans[i] > capacity) {
                return false;
            }
        }

        return true;
    }
};
