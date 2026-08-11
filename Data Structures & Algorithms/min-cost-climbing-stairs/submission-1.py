class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        costDict = {}
        costDict[0] = 0
        costDict[1] = 0

        def minCost(stairCount):
            if stairCount in costDict:
                return costDict[stairCount]
            
            prevStep = minCost(stairCount - 1) + cost[stairCount - 1]
            prevPrevStep = minCost(stairCount - 2) + cost[stairCount - 2]
            retVal = min(prevStep, prevPrevStep)
            costDict[stairCount] = retVal

            return retVal
        
        return minCost(len(cost))