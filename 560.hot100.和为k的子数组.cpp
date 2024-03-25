class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> pre(nums.size() + 1);

        pre[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int curSum = pre[i + 1] - pre[j];
                // printf("%d\n", curSum);
                if (curSum == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

