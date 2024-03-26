class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size() + 1, 1);
        vector<int> right(nums.size() + 1, 1);
        vector<int> ans;

        for (int i = 1; i <= nums.size(); i++) {
            left[i] = left[i - 1] * nums[i - 1];
            // printf("left[%d]: %d\n",i, left[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
            // printf("right[%d]: %d\n",i, right[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            int cur = left[i] * right[i + 1];
            ans.push_back(cur);
        }


        return ans;
    }
};
