class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = [asteroids[0]]

        def isPositive(n):
            if n > 0:
                return True
            else:
                return False

        for a in asteroids[1:]:
            while True:
                if (not stack) or (isPositive(stack[-1]) == isPositive(a)) or (not isPositive(stack[-1])):
                    stack.append(a)
                    break
                else:
                    l = abs(stack[-1])
                    r = abs(a)

                    if l < r:
                        stack.pop()
                    elif l == r:
                        stack.pop()
                        break
                    else:
                        break
        
        return stack