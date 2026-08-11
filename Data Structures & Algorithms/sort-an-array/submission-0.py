class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) < 2:
            return nums
        
        mid = len(nums) // 2
        left = nums[:mid]
        right = nums[mid:]

        leftSorted = self.sortArray(left)
        rightSorted = self.sortArray(right)

        l = 0
        r = 0
        res = []

        while (l < len(leftSorted)) and (r < len(rightSorted)):
            if (leftSorted[l] <= rightSorted[r]):
                res.append(leftSorted[l])
                l += 1
            else:
                res.append(rightSorted[r])
                r += 1

        if l < len(leftSorted):
            ptr = l
            remaining = leftSorted
        else:
            ptr = r
            remaining = rightSorted

        for i in range(ptr, len(remaining)):
            res.append(remaining[i])

        return res