class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int window = 0;
        int maxSum = INT_MIN;

        while (right < nums.size()) {
            window += nums[right];
            right++;

            maxSum = max(maxSum, window);

            while (window < 0) {
                window -= nums[left];
                left++;
                // maxSum = max(maxSum, window);
            }
        }

        return maxSum;
    }
};
