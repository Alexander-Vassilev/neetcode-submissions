import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = max(piles)
        isHigh = True

        while True:
            rate = (low + high) // 2
            time = 0

            for pile in piles:
                time += math.ceil(pile / rate)

            print("low" + str(low))
            print("high" + str(high))
    
            if time <= h:
                isHigh = False
                high = rate - 1
            elif time > h:
                isHigh = True
                low = rate + 1
        
            if low > high:
                if isHigh:
                    return rate + 1
                else:
                    return rate