class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        l = nums
        l.sort()
        initRight = len(l) - 1
        retVal = set()

        for i in range(len(l)):
            if (nums[i] > 0):
                break

            left = i + 1
            right = initRight

            while left < right:
                sum = l[i] + l[left] + l[right]

                if sum == 0:
                    triplet = (l[i], l[left], l[right])
                    retVal.add(triplet)
                    left += 1
                elif sum < 0:
                    left += 1
                else:
                    right -= 1
        
        retVal = list(retVal)

        for i in range(len(retVal)):
            retVal[i] = list(retVal[i])

        return retVal
            
