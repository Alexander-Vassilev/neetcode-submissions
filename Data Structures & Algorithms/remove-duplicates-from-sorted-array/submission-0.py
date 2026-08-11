class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        curr = None
        i = 0

        while i < len(nums):
            if nums[i] == curr:
                nums.pop(i)
            else:
                curr = nums[i]
                i += 1
            
        return len(nums)