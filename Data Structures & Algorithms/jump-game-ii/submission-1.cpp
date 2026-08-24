class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        nums[len - 1] = 0;

        for (int i = len - 2; i >= 0; i--) {
            int minJumps = 1e9;
            int itLimit = min(i + nums[i] + 1, len);

            for (int j = i + 1; j < itLimit; j++) {
                minJumps = min(minJumps, nums[j]);
            }

            nums[i] = minJumps + 1;
        }

        return nums[0];
    }
};
