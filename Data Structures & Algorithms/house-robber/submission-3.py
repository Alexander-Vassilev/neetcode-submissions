class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)

        memo1 = nums[0]
        memo2 = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            temp = max(memo1 + nums[i], memo2)
            memo1 = memo2
            memo2 = temp
        
        return memo2