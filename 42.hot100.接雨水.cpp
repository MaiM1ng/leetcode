class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> l_max(n);
        vector<int> r_max(n);

        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            l_max[i] = max(height[i], l_max[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            r_max[i] = max(height[i], r_max[i + 1]);
        }

        for (int i = 0; i < height.size(); i++) {
            ans += min(l_max[i], r_max[i]) - height[i];
        }
        
        return ans;
    }
};
