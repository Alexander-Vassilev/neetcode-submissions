class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        area = 0
        diff = right - left
        optimalChoices = (left, right)

        while left < right:
            height = min(heights[left], heights[right])
            area = max(area, diff * height)
            print(str(left) + ", " + str(right))

            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
            
            diff -= 1
        
        return area
        