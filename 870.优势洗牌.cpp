class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        priority_queue<pair<int, int>> pq;
        int left = 0;
        int right = n - 1;
        vector<int> res(n);

        sort(nums1.begin(), nums1.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(nums2[i], i));
        }

        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            if (num < nums1[left]) {
                res[idx] = nums1[left++];
            } else {
                res[idx] = nums1[right--];
            }
        }

        return res;
    }
};
