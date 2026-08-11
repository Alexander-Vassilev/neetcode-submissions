class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = len(nums)
        low = 0
        high = l - 1

        while True:
            index = low + ((high - low) // 2)

            if (nums[index - 1] > nums[index]) or (low == high):
                return nums[index]
            
            if nums[high] > nums[index]:
                high = index - 1
            else:
                low = index + 1