class Solution:
    def isHappy(self, n: int) -> bool:
        done = False
        res = n
        seenList = []

        while not done:
            l = str(res)
            res = 0

            for i in range(len(l)):
                digit = int(l[len(l) - 1 - i])
                res += digit * digit
            
            print(seenList)
            
            if res == 1:
                return True
            elif res in seenList:
                return False
            
            seenList.append(res)