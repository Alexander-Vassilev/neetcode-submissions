class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = len(nums)
        small = 0
        large = l - 1
        i = 0

        while True:
            i += 1
            index = small + ((large - small) // 2)
            #print(small)
            #print(large)
            #print(nums[index])
            #print()

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