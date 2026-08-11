class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = float('-inf')
        currSum = float('-inf')

        for i in range(len(nums)):
            if nums[i] > (currSum + nums[i]):
                currSum = nums[i]
            else:
                currSum += nums[i]
            
            if currSum > maxSum:
                maxSum = currSum
        
        return maxSum