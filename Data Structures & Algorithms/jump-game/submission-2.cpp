class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return true;
        int lastValidIdx = len - 1;

        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] >= lastValidIdx - i) lastValidIdx = i;
        }

        return !lastValidIdx;
    }
};
