import math

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        retList = []
        width = len(matrix[0])
        height = len(matrix)
        numLoop = math.ceil(min(width, height) / 2)

        for i in range(0, numLoop):
            iterWidth = width - i - 1
            iterHeight = height - i - 1
            terminateEarly = False

            if (iterWidth - i <= 0) or (iterHeight - i <= 0):
                iterHeight += 1
                terminateEarly = True

            for j in range(i, iterWidth):
                retList.append(matrix[i][j])
                
            for j in range(i, iterHeight):
                retList.append(matrix[j][width - 1 - i])

            if terminateEarly:
                break

            for j in range(i, iterWidth):
                retList.append(matrix[height - 1 - i][width - 1 - j])
                
            for j in range(i, iterHeight):
                retList.append(matrix[height - 1 - j][i])

        return retList