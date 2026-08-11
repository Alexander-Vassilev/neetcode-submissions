class Solution:
    def trap(self, height: List[int]) -> int:
        leftMax = [0]
        currLeftMax = 0
        rightMax = [0]
        currRightMax = 0
        
        for i in range(1, len(height)):
            index = i - 1

            if height[index] > currLeftMax:
                currLeftMax = height[index]
                leftMax.append(currLeftMax)
            else:
                leftMax.append(currLeftMax)
            
            index = len(height) - i

            if height[index] > currRightMax:
                currRightMax = height[index]
                rightMax.append(currRightMax)
            else:
                rightMax.append(currRightMax)

        totalWater = 0
        reverseIndex = len(height) - 1

        for i in range(len(height)):
            totalWater += max(min(leftMax[i], rightMax[reverseIndex - i]) - height[i], 0)
        
        return totalWater