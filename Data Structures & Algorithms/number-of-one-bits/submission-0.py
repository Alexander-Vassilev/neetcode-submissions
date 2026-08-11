class Solution:
    def hammingWeight(self, n: int) -> int:
        num = 0
        temp = 1

        for i in range(32):
            if temp & n == temp:
                num += 1
            
            temp *= 2
        
        return num