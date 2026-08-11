class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        biggest = max(nums)
        smallest = min(nums)
        l = [0] * (biggest - smallest + 1)

        for i in range(len(nums)):
            l[nums[i] - smallest] += 1
        
        counter = 0
        maxCounter = 0

        for i in range(len(l)):
            if (l[i] > 0):
                counter += 1
            else:
                maxCounter = max(counter, maxCounter)
                counter = 0
        
        return max(counter, maxCounter)