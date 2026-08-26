class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (n < 0) {
            N = -n;
            x = 1.0 / x;
        }

        double res = 1.0;

        while (N > 0) {
            if (N & 1) res *= x;

            x *= x;
            N >>= 1;
        }

        return res;
    }
};
