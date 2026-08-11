class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        leftPointer = 0
        rightPointer = 0
        seenSet = {s[0]}
        done = False
        maxLen = 1

        while not done:
            if rightPointer >= len(s) - 1:
                done = True
            else:
                rightPointer += 1

                if s[rightPointer] in seenSet:
                    seenSet.add(s[rightPointer])
                    seenSet.remove(s[leftPointer])
                    leftPointer += 1
                    rightPointer -= 1
                else:
                    maxLen = max(maxLen, rightPointer - leftPointer + 1)
                    seenSet.add(s[rightPointer])
                
        return maxLen