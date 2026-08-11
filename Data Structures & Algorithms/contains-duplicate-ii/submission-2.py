class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return False
        
        seen = set()
        
        for i in range(min(len(nums), k + 1)):
            if nums[i] in seen:
                return True
            
            seen.add(nums[i])
        
        for i in range(k + 1, len(nums)):
            seen.remove(nums[i - k - 1])

            if nums[i] in seen:
                return True

            seen.add(nums[i])
        
        return False