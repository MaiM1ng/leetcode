class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n);
        vector<int> ans(n);

        for (vector<int> each: bookings) {
            int first = each[0];
            int last = each[1];
            int seats = each[2];
            diff[first - 1] += seats;
            if (last < n) diff[last] -= seats;
        }

        ans[0] = diff[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + diff[i]; 
        }

        return ans;
    }
};
