import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        text = s.lower()
        text = re.sub(r'[^a-zA-Z0-9]', '', text)
        left = 0
        right = len(text) - 1

        while left < right:
            if not (text[left] == text[right]):
                return False
            
            left += 1
            right -= 1
        
        return True