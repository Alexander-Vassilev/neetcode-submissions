class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        retList = [[]]        
        
        for num in nums:
            currLen = len(retList)

            for i in range(currLen):
                retList.append(list(retList[i]))
                retList[-1].append(num)
        
        return retList