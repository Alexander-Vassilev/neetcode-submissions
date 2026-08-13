class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int runningSum = 0;
        int len = nums.size();

        auto getIndex = [&] (int a) {
            return a % len;
        };
        
        for (int i = 1; i < len; i++) {
            runningSum += nums[getIndex(i - 1)];

            for (int j = 0; j < len; j++) {
                maxSum = max(runningSum, maxSum);
                runningSum -= nums[j];
                runningSum += nums[getIndex(j + i)];
            }
        }

        runningSum += nums[len - 1];
        maxSum = max(maxSum, runningSum);

        return maxSum;
    }
};