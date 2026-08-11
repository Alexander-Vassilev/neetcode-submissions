class Solution:
    def countBits(self, n: int) -> List[int]:
        retList = [0] * (n + 1)

        for i in range(n + 1):
            temp = i

            while temp:
                temp &= temp - 1
                retList[i] += 1
        
        return retList