class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2

        prevprev = 1
        prev = 2

        for i in range(3, n + 1):
            temp = prev + prevprev
            prevprev = prev
            prev = temp
        
        return prev
