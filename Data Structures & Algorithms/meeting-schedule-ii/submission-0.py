"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        startList = []
        endList = []

        for interval in intervals:
            startList.append(interval.start)
            endList.append(interval.end)
        
        startList.sort()
        endList.sort()

        startPtr = 0
        endPtr = 0
        maxDistance = 0

        while startPtr < len(intervals):
            if startList[startPtr] < endList[endPtr]:
                startPtr += 1
                maxDistance = max(maxDistance, abs(startPtr - endPtr))
            else:
                endPtr += 1
        
        return maxDistance