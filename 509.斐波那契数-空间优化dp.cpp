class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }

        int fibn1 = 1;
        int fibn2 = 0;
        int ans;

        for (int i = 2; i <= n;i++) {
            ans = fibn1 + fibn2;
            fibn2 = fibn1;
            fibn1 = ans;
        }

        return ans;
    }
};
