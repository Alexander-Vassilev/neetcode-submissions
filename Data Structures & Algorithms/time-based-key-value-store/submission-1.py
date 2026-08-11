class TimeMap:
    def __init__(self):
        self.keyDict = {}        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.keyDict:
            self.keyDict[key].append((timestamp, value))
        else:
            self.keyDict[key] = [(timestamp, value)]

    def get(self, key: str, timestamp: int) -> str:
        if key in self.keyDict:
            l = 0
            r = len(self.keyDict[key]) - 1
            retVal = ""

            while l <= r:
                mid = l + ((r - l) // 2)

                if self.keyDict[key][mid][0] == timestamp:
                    return self.keyDict[key][mid][1]
                elif self.keyDict[key][mid][0] < timestamp:
                    l = mid + 1
                    retVal = self.keyDict[key][mid][1]
                else:
                    r = mid - 1
            
            return retVal
        else:
            return ""