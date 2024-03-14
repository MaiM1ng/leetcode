class Solution {
public:

    vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {
        int low = start;
        int high = nums.size() - 1;
        vector<vector<int>> ans;

        while (low < high) {
            int a = nums[low];
            int b = nums[high];
            int sum = a + b;
            if (sum > target) {
                high--;
            } else if (sum < target) {
                low++;
            } else {
                ans.push_back({a, b});
                while (low < high && nums[low] == a) low++;
                while (low < high && nums[high] == b) high--;
            }
        }

        return ans;
    }


    vector<vector<int>> threeSumTarget(vector<int>& nums, int target) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> twoList = twoSumTarget(nums, i + 1, target - nums[i]);
            for (vector<int> each : twoList) {
                each.push_back(nums[i]);
                res.push_back(each);
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumTarget(nums, 0);
    }
};
