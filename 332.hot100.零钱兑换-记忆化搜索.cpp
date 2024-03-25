class Solution {
public:
    vector<int> memo;

    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount + 1, -1);

        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int amount) {
        // Base case
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return -1;
        }

        if (memo[amount] != -1) {
            return memo[amount];
        }

        int res = INT_MAX;

        for (int coin : coins) {
            int sub_res = dp(coins, amount - coin);

            if (sub_res == -1) {
                continue;
            }

            res = min(res, sub_res + 1);
        }

        memo[amount] = (res == INT_MAX ? -1 :res);
        return memo[amount];
    }
};
