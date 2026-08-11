class Solution:
    def isValid(self, s: str) -> bool:
        bracketSet = {('[', ']'), ('{', '}'), ('(', ')')}
        stack = []
        
        for i in range(len(s)):
            openingBracketType = next((t for t in bracketSet if t[0] == s[i]), None)

            if openingBracketType:
                stack.append(openingBracketType[0])
                continue
            
            closingBracketType = next((t for t in bracketSet if t[1] == s[i]), None)
            
            if (not stack) or (not stack[-1] == closingBracketType[0]):
                return False
            else:
                stack.pop()
        
        if not stack:
            return True
        else:
            return False