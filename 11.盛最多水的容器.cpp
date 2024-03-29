class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int ans = 0;

        while (low < high) {
            int tall = min(height[low], height[high]);
            int width = high - low;
            ans = max(ans, tall * width);
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }

        return ans;
    }
};
