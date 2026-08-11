class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda el: el[1])
        count = 0
        lastKeptEl = 0
        print(intervals)

        for i in range(1, len(intervals)):
            if intervals[i][0] < intervals[lastKeptEl][1]:
                count += 1
            else:
                lastKeptEl = i
        
        return count