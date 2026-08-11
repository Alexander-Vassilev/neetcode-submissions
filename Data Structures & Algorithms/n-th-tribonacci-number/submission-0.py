class Solution:
    def tribonacci(self, n: int) -> int:
        memo = {0: 0, 1: 1, 2: 1}
        retVal = 0

        if n < 3:
            return memo[n]

        for i in range(3, n + 1):
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3]

        return memo[n]