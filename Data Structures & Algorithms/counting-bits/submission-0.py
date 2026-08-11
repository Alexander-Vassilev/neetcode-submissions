class Solution:
    def countBits(self, n: int) -> List[int]:
        retList = []

        for i in range(n + 1):
            temp = i
            count = 0

            while temp:
                temp &= temp - 1
                count += 1
            
            retList.append(count)
        
        return retList