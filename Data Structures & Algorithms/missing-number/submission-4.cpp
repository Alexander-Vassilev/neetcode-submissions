class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size(); // Start with n
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;        // XOR the index
            res ^= nums[i];  // XOR the value
        }
        return res;
    }
};
