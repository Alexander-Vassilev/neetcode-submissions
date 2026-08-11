class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seenSet = set()

        for i in range(len(nums)):
            if nums[i] in seenSet:
                return True
            
            seenSet.add(nums[i])
        
        return False

        