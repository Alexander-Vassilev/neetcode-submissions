import math

class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask =0xFFFFFFFF

        while b:
            carry = (a & b) << 1
            a = (a ^ b) & mask
            b = carry & mask

        if a > mask // 2:
            return ~(a ^ mask)
        else:
            return a