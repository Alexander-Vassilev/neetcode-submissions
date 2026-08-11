class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        retVal = 0

        for num in nums:
            retVal = retVal ^ num

        return retVal