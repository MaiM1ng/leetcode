class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid;
        double res = 0;
        if ((m + n) % 2 == 0) {
            mid = (m + n) / 2 - 1;
        } else {
            mid = (m + n) / 2;
        }

        int p = 0;
        int q = 0;

        while (p < m && q < n) {
            if (nums1[p] < nums2[q]) {
                if (p + q == mid) {
                    res += nums1[p];
                } else if (p + q == mid + 1 && (m + n) % 2 == 0) {
                    res += nums1[p];
                }
                p++;
            } else {
                if (p + q == mid) {
                    res += nums2[q];
                } else if (p + q == mid + 1 && (m + n) % 2 == 0) {
                    res += nums2[q];
                }
                q++;
            }
        }

        while (p < m) {
            if (p + q == mid) {
                res += nums1[p];
            } else if (p + q == mid + 1 && (m + n) % 2 == 0) {
                res += nums1[p];
            }
            p++;
        }

        while (q < n) {
            if (p + q == mid) {
                res += nums2[q];
            } else if (p + q == mid + 1 && (m + n) % 2 == 0) {
                res += nums2[q];
            }
            q++;
        }

        // printf("res = %f\n", res);
        return (m + n) % 2 == 0 ? res / 2 : res;
    }
};
