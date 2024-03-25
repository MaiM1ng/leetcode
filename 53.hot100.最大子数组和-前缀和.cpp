class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        vector<int> preSum(nums.size() + 1, 0);

        preSum[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        int minVal = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minVal = min(preSum[i], minVal);
            ans = max(ans, preSum[i + 1] - minVal);
        }

        return ans;
    }
};
