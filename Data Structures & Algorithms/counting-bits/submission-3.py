class Solution:
    def countBits(self, n: int) -> List[int]:
        retList = [0] * (n + 1)
        power = 1

        for i in range(1, n + 1):
            if power * 2 == i:
                power *= 2
            
            retList[i] = retList[i - power] + 1
        
        return retList