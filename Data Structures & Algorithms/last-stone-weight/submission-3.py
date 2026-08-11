class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if not stones:
            return 0

        for i in range(len(stones)):
            stones[i] = -stones[i]
    
        heapq.heapify(stones)

        while len(stones) > 1:
            print(stones)
            challenger1 = abs(heapq.heappop(stones))
            challenger2 = abs(heapq.heappop(stones))

            if not challenger1 == challenger2:
                heapq.heappush(stones, challenger2 - challenger1)

        if stones:
            return abs(stones[0])
        else:
            return 0