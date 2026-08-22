class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> maxSubsequences(len, 1);
        int retVal = 1;

        for (int i = len - 2; i >= 0; i--) {
            int curr = nums[i];
            int l = 1;

            for (int j = i + 1; j < len; j++) {
                if (nums[j] > curr) {
                    l = max(l, 1 + maxSubsequences[j]);
                }
            }

            maxSubsequences[i] = l;
            retVal = max(retVal, l);
        }

        return retVal;
    }
};
