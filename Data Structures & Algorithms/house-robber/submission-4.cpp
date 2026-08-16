class Solution {
public:
    int rob(vector<int>& nums) {
        int ret = 0;
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            ret = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = ret;
        }

        return ret;
    }
};
