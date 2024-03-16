class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        int ans = 0;

        // if (x < 0) {
        //     isNeg = true;
        //     x = -x;
        // }

        while (x) {
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) {
                return 0;
            }
            int num = x % 10;
            ans *= 10;
            ans += num;
            x /= 10;
        }

        // if (isNeg) ans *= -1;

        return ans;
    }
};
