class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), cmp);

        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int cur_l = intervals[i][0];
            int cur_r = intervals[i][1];

            if (cur_l > right) {
                ans.push_back({left, right});
                left = cur_l;
                right = cur_r;
            } else if (cur_l == right) {
                left = left;
                right = cur_r;
            } else {
                left = min(left, cur_l);
                right = max(cur_r, right);
            }
        }

        ans.push_back({left, right});

        return ans;
    }
};
