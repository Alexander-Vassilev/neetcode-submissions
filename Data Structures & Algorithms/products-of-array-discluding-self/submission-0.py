class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        retList = []
        
        for i in range(len(nums)):
            result = 1

            for j in range(len(nums)):
                if (j == i):
                    continue
                else:
                    result *= nums[j]

            retList.append(result)

        return retList