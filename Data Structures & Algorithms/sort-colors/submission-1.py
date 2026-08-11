class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numEach = {0: 0, 1: 0, 2:0}

        for num in nums:
            numEach[num] += 1
        
        
        target = 0
        index = 0
        i = 0

        while i < len(nums):
            if index < numEach[target]:
                nums[i] = target
                index += 1
                i += 1
            else:
                target += 1
                index = 0
                