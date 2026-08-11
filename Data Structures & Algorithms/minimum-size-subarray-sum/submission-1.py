class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        totalSum = nums[0]
        minNumElements = float('inf')
        left = 0
        right = 0

        while left <= right < len(nums):
            if totalSum >= target:
                minNumElements = min(minNumElements, right - left + 1)
                totalSum -= nums[left]
                left += 1
            else:
                right += 1

                if right < len(nums):
                    totalSum += nums[right]

        if minNumElements == float('inf'):
            return 0
        
        return minNumElements