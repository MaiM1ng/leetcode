class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = cur; j < nums.size(); j++) {
                if (nums[j] == i) {
                    int tmp = nums[j];
                    nums[j] = nums[cur];
                    nums[cur] = tmp;
                    cur++;
                }
            }
        }
    }
};
