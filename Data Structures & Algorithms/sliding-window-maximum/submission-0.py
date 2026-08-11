class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        numWindows = len(nums) - k + 1
        maximums = [None] * numWindows
        newL = []

        for i in range(len(nums)):
            newL.append((i, nums[i]))

        newL = sorted(newL, key=lambda x: -x[1])

        for i in range(len(newL)):
            pos = newL[i][0]

            for j in range(max(pos - k + 1, 0), min(pos + 1, numWindows)):
                if maximums[j] == None:
                    maximums[j] = newL[i][1]
        
        return maximums