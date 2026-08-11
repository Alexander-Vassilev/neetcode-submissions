class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int xorNoSkip = 0;
        int xorSkip = 0;

        for (int i = 1; i <= len; i++) {
            xorNoSkip ^= i;
        }

        for (int i = 0; i < len; i++) {
            xorSkip ^= nums[i];
        }

        return xorNoSkip ^ xorSkip;
    }
};
