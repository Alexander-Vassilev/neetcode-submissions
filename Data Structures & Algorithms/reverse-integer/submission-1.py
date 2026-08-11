class Solution:
    def reverse(self, x: int) -> int:
        isPositiveMult = 1 if x > 0 else -1
        maxVal = [2, 1, 4, 7, 4, 8, 3, 6, 4, 7]
        digitList = []
        if x == -2147483648:
            return 0
        x = abs(x)

        while x:
            temp = x % 10
            digitList.append(temp)
            x = x // 10
            #print(x)
        
        #print(digitList)

        if len(digitList) > 10:
            return 0
        elif len(digitList) == 10:
            isEqual = True

            for i in range(10):
                #print("passed")
                if digitList[i] > maxVal[i]:
                    return 0
                elif digitList[i] < maxVal[i]:
                    isEqual = False
                    break
                
        multiplier = 1
        retVal = 0
        digitList.reverse()

        for digit in digitList:
            retVal += multiplier * digit
            #print(retVal)
            multiplier *= 10

        return retVal * isPositiveMult

sol = Solution()
tests = []
tests.append((1234, 4321))

#for test in tests:
#    #assert sol.reverse(test[0]) == test[1], "test failed, got " + str(sol.reverse(test[0])) + ", expected " + str(test[1])
#    sol.reverse(test[0])