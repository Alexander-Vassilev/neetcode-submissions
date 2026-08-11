import heapq

class MedianFinder:

    def __init__(self):
        self.heapSmall = []
        self.heapLarge = []
        heapq.heapify(self.heapSmall)
        heapq.heapify(self.heapLarge)

    def addNum(self, num: int) -> None:
        heapq.heappush(self.heapLarge, num)
        
        if (self.heapSmall and num < -self.heapSmall[0]) or (len(self.heapLarge) > len(self.heapSmall) + 1):
            el = heapq.heappop(self.heapLarge)
            heapq.heappush(self.heapSmall, -el)
        if (len(self.heapSmall) > len(self.heapLarge)):
            el = heapq.heappop(self.heapSmall)
            heapq.heappush(self.heapLarge, -el)
        
        print(self.heapSmall)
        print(self.heapLarge)
        print()

    def findMedian(self) -> float:
        if len(self.heapSmall) == len(self.heapLarge):
            el1 = -self.heapSmall[0]
            el2 = self.heapLarge[0]

            return float(el1 + el2) / 2.0
        else:
            return self.heapLarge[0]
        