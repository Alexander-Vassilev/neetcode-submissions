class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals = sorted(intervals, key=lambda x: x[0])
        retList = [intervals[0]]

        for i in range(1, len(intervals)):
            if intervals[i][0] <= retList[-1][1]:
                retList[-1] = [retList[-1][0], max(intervals[i][1], retList[-1][1])]
            else:
                retList.append(intervals[i])
        
        return retList