class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = {}
        memo[(1, 2)] = 1
        memo[(2, 1)] = 1

        def uniqueHelper(m, n):
            if (m, n) in memo:
                return memo[(m, n)]
            elif m == 1 or n == 1:
                return 1
            
            memo[(m, n)] = uniqueHelper(m - 1, n) + uniqueHelper(m, n - 1)
            
            return memo[(m, n)]

        return uniqueHelper(m, n)