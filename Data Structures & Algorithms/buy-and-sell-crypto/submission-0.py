class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #[4, 5, 7, 4, 2, 6, 8, 6]
        done = False
        left = prices[0]
        right = 0
        maxDiff = 0

        while not done:
            if right >= len(prices) - 1:
                done = True
            else:
                if prices[right] >= left:
                    right += 1
                    maxDiff = max(maxDiff, prices[right] - left)
                else:
                    left = prices[right]
        
        return maxDiff