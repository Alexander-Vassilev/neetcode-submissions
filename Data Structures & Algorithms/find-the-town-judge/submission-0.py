class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # build map of person -> num people that trust person
        # build map of person -> num people they trust
        trustedMap = [0] * (n + 1)
        trustingMap = [0] * (n + 1)

        for edge in trust:
            trustingMap[edge[0]] += 1
            trustedMap[edge[1]] += 1
        
        for i in range(1, n + 1):
            if trustedMap[i] == n - 1 and trustingMap[i] == 0:
                return i
        
        return -1