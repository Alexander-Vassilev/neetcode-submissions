class Solution {
public:
    double myPow(double x, int n) {
        double res = x;
        uint64_t power = 1;
        uint64_t newPower = 0;
        uint64_t absN = 0;
        if (n < 0) {
            absN = -n;
            x = 1.0 / x;
        } else {
            absN = n;
        }
        map<int, double> pows;

        if (x == 1.0) return 1.0;
        else if (x == -1.0) {
            if (n % 2) return -1.0;
            return 1.0;
        } else if (n == 0) return 1.0;

        while ((power << 1) <= absN) {
            pows[power] = res;
            res *= res;
            if (!res) return res;
            power <<= 1;
        }

        newPower = power;

        while (newPower != absN) {
            int subPower = power >> 1;

            while (subPower + newPower > absN) {
                subPower >>= 1;
            }

            res *= pows[subPower];
            if (!res) return res;
            newPower += subPower;
        }

        if (n < 0) return 1.0 / res;

        return res;
    }
};
