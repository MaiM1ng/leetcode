class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {   // 不能小于0
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
