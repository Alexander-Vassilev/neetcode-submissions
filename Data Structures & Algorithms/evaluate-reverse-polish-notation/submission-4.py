class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = {'+', '-', '*', '/'}
        numStack = []

        for i in range(len(tokens)):
            if tokens[i] in operators:
                operandTwo = numStack[-1]
                numStack.pop()
                operandOne = numStack[-1]
                numStack.pop()
                op = tokens[i]
                result = 0

                if op == '+':
                    result = operandOne + operandTwo
                elif op == '*':
                    result = operandOne * operandTwo
                elif op == '/':
                    result = int(float(operandOne) / operandTwo)
                elif op == '-':
                    result = operandOne - operandTwo
                
                numStack.append(result)
            else:
                numStack.append(int(tokens[i]))
        
        return numStack[0]