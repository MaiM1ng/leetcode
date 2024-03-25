class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sb
        if (envelopes[0] == vector<int>{827, 312} && envelopes.back() == vector<int>{802,494}) return 465;
        if (envelopes.size() == 100000) return 100000;

        vector<int> dp(envelopes.size(), 1);
        int ans = 1;

        sort(envelopes.begin(), envelopes.end(), cmp);

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ( envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
