class Solution {
public:

    vector<vector<int>> twoSumTarget(vector<int>& nums, int start, long target) {
        int left = start;
        int right = nums.size() - 1;
        vector<vector<int>> ans;

        while (left < right) {
            int a = nums[left];
            int b = nums[right];
            long sum = a + b;
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                ans.push_back({a, b});
                while (left < right && nums[left] == a) left++;
                while (left < right && nums[right] == b) right--;
            }
        }

        return ans;
    }

    vector<vector<int>> treeSumTarget(vector<int>& nums, int start, long target) {
        vector<vector<int>> ans;

        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> twoList = twoSumTarget(nums, i + 1, target - nums[i]);
            for (vector<int> v : twoList) {
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }

        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sb
        long tar = (long)target;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> threeList = treeSumTarget(nums, i + 1, tar - nums[i]);
            for (vector<int> v : threeList) {
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }

        return ans;
    }
};
