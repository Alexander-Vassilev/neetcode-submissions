class Solution:
    def search(self, nums: List[int], target: int) -> int:
        length = len(nums)
        pointer = math.floor(length / 2)
        delta = math.ceil(length / 2)
        prevIndex = 0
        l = 0
        r = length - 1

        while r - l >= 0:
            pointer = (r + l // 2)
            print('r: ' + str(r))
            print('l: ' + str(l))

            if nums[pointer] == target:
                return pointer
            elif nums[pointer] < target:
                l = pointer + 1
            elif nums[pointer] > target:
                r = pointer - 1
        
        return -1