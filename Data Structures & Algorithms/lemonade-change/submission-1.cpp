class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tenCount = 0;

        for (auto& bill : bills) {
            if (bill == 5) {
                fiveCount++;
            } else if (bill == 10) {
                if (fiveCount) {
                    fiveCount--;
                    tenCount++;
                } else {
                    return false;
                }
            } else {
                if (fiveCount > 2) {
                    fiveCount -= 3;
                } else if (tenCount && fiveCount) {
                    fiveCount--;
                    tenCount--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};