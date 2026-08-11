class Solution:
    def addBinary(self, a: str, b: str) -> str:
        maxLen = max(len(a), len(b))
        carryBit = 0
        retVal = ""

        for i in range(maxLen):
            if i >= len(a):
                aBit = 0
            else:
                aBit = int(a[len(a) - i - 1])
            
            if i >= len(b):
                bBit = 0
            else:
                bBit = int(b[len(b) - i - 1])

            res = aBit + bBit + carryBit

            if res > 1:
                carryBit = 1
            else:
                carryBit = 0
            
            retVal += str(res % 2)

        if carryBit:
            retVal += "1"
        
        retVal = retVal[::-1]

        return retVal

sol = Solution()
tests = []

tests.append(("111", "10", "1001"))
tests.append(("0", "0", "0"))
tests.append(("11111", "0", "11111"))
tests.append(("01001", "01001", "10010"))
tests.append(("101010", "010101", "111111"))
tests.append(("101001011010101", "0101111010011", "101111010101000"))

for test in tests:
    assert sol.addBinary(test[0], test[1]) == test[2], "test failed"