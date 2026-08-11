class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = len(nums)
        small = 0
        large = l - 1

        while True:
            index = small + ((large - small) // 2)

            if nums[index] == target:
                return index
            elif nums[index] < nums[large]:
                if target > nums[large]:
                    large = index - 1
                elif target < nums[large]:
                    if target < nums[index]:
                        large = index - 1
                    else:
                        small = index + 1
                else:
                    return large
            else:
                if target < nums[small]:
                    small = index + 1
                elif target > nums[small]:
                    if target < nums[index]:
                        large = index - 1
                    else:
                        small = index + 1
                else:
                    return small

            if small > large:
                return -1