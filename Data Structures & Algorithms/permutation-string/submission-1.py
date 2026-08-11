class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1Length = len(s1)
        s2Length = len(s2)

        if s1Length > s2Length:
            return False

        charCounter = {}
        isFound = True
        
        for i in range(s1Length):
            if s1[i] in charCounter:
                charCounter[s1[i]] += 1
            else:
                charCounter[s1[i]] = 1

        for i in range(s1Length):
            if s2[i] in charCounter:
                charCounter[s2[i]] -= 1
            
        if all(value == 0 for value in charCounter.values()):
                return True

        for i in range(s1Length, s2Length):
            if s2[i - s1Length] in charCounter:
                charCounter[s2[i - s1Length]] += 1

            if s2[i] in charCounter:
                charCounter[s2[i]] -= 1
            
            if all(value == 0 for value in charCounter.values()):
                return True

        return False