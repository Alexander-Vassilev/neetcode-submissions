class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        i = 0
        
        while left != right:
            right = right >> 1
            left = left >> 1
            i += 1
        
        return right << i
        
        
        #retVal = left
        #curr = left + 1
        #shiftCount = 0
        ##print(bin(left))
        ##print(bin(right))
        #
        #while curr <= right:
        #    print(bin(retVal))
        #    print(bin(right))
        #    print(bin(curr))
        #    print("     ")
        #    while True and shiftCount < 10:
        #        if (retVal & 1 == 0) and retVal:
        #            right = right >> 1
        #            retVal = retVal >> 1
        #            curr = curr >> 1
        #            print("entered shifter")
        #            print(bin(retVal))
        #            print(bin(right))
        #            print(bin(curr))
        #            print("     ")
        #            shiftCount += 1
        #        else:
        #            break
        #    
        #    retVal &= curr
        #    curr += 1
        #
        #return retVal << shiftCount