class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if (len(s) < len(t)) or (not s) or (not t):
            return ""

        charDict = {}

        for i in range(len(t)):
            charDict[t[i]] = charDict.get(t[i], 0) + 1
        
        left = 0
        right = 0
        shortestSubstring = ""
        currSubstring = s[0]
        currentlySat = False

        print(charDict)

        if s[0] in charDict:
            charDict[s[0]] -= 1

        while (right < len(s)) or currentlySat:
            #print(charDict)
            print(currSubstring)
            if all(value <= 0 for value in charDict.values()):
                currentlySat = True

                if (not shortestSubstring) or (len(currSubstring) < len(shortestSubstring)):
                    if len(currSubstring) == 1:
                        return currSubstring
                    
                    shortestSubstring = currSubstring
            else:
                currentlySat = False

            if currentlySat:
                if s[left] in charDict:
                    charDict[s[left]] += 1

                left += 1
                currSubstring = currSubstring[1:]
            else:
                right += 1

                if right < len(s):
                    currSubstring = currSubstring + s[right]
                    
                    if s[right] in charDict:
                        charDict[s[right]] -= 1
        
        return shortestSubstring