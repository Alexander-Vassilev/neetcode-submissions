class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        output = [0] * len(temperatures)

        for i in range(len(temperatures)):
            if (not stack) or (temperatures[stack[-1]] > temperatures[i]):
                stack.append(i)
            else:
                print(stack)
                print(temperatures[i])

                while stack:
                    if temperatures[stack[-1]] < temperatures[i]:
                        output[stack[-1]] = i - stack[-1]
                        print(stack[-1])
                        stack.pop()
                    else:
                        break
                
                stack.append(i)
        
        return output