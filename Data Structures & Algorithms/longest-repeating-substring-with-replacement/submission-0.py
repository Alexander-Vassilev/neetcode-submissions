class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if not s:
            return 0

        charDict = {}
        leftPointer = 0
        maxLength = 0

        for rightPointer in range(len(s)):
            if s[rightPointer] not in charDict:
                charDict[s[rightPointer]] = 1
            else:
                charDict[s[rightPointer]] += 1

            windowSize = rightPointer - leftPointer + 1
            max_value = max(charDict.values())

            if ((windowSize - max_value) <= k):
                maxLength = max(maxLength, windowSize)
            else:
                charDict[s[leftPointer]] -= 1
                leftPointer += 1
        
        return maxLength