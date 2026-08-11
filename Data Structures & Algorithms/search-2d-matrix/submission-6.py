class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix[0]) < 1:
            return False
        
        small = 0
        big = len(matrix) - 1
        row = 0
        column = 0

        while True:
            row = (small + big) // 2

            print(small)
            print(big)

            if matrix[row][0] > target:
                big = row - 1
            elif matrix[row][-1] < target:
                small = row + 1
            else:
                small = 0
                big = len(matrix[0]) - 1
                break
            
            if small > big:
                return False
        
        while True:
            column = (small + big) // 2

            if matrix[row][column] == target:
                return True
            elif matrix[row][column] < target:
                small = column + 1
            else:
                big = column - 1

            if small > big:
                return False 