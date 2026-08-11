import heapq
import math

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        distanceToCoords = {}
        retList = []

        for point in points:
            distance = -math.sqrt(point[0] * point[0] + point[1] * point[1])
            
            if distance in distanceToCoords:
                distanceToCoords[distance].append(point)
            else:
                distanceToCoords[distance] = [point]

            if len(heap) < k:
                heapq.heappush(heap, distance)
            else:
                maxVal = heap[0]

                if distance > maxVal:
                    heapq.heappop(heap)
                    heapq.heappush(heap, distance)

        while heap:
            el = heapq.heappop(heap)
            retList.append(distanceToCoords[el].pop())
        
        return retList