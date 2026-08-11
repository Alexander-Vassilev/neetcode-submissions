class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        i = 0

        while left <= right and i < 10:
            mid = left + (right - left) // 2
            #print(mid)

            if nums[mid] == target:
                return mid
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
            
            i += 1
        
        # 0 1 2 3 4 5
        return left

sol = Solution()

tests = []
tests.append(([1, 2, 3, 4, 5, 6], 10, 6))
tests.append(([1, 2, 3, 4, 5, 6], -1, 0))
tests.append(([1, 2, 3, 4, 5, 6], 2, 1))
tests.append(([1, 2, 4], 3, 2))
tests.append(([0], 0, 0))
tests.append(([-4, -2, 3, 4, 5, 6], 6, 5))

for test in tests:
    res = sol.searchInsert(test[0], test[1])
    assert res == test[2], "test failed: expected " + str(test[2]) + ", instead got " + str(res)