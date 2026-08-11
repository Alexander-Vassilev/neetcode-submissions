class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix[0]) == 0:
            return False
        
        small = 0
        large = len(matrix) - 1
        row = 0
        column = 0
        done = False
        foundRow = False

        # Iterate up and down
        while (not foundRow):
            row = (small + large) // 2

            if matrix[row][0] > target:
                large = row - 1
            elif matrix[row][-1] < target:
                small = row + 1
            else:
                foundRow = True
                small = 0
                large = len(matrix[0]) - 1
        
            if small > large:
                return False
                
        # Iterate left to right
        while (not done):
            column = (small + large) // 2
            a = matrix[row][column]

            if a == target:
                return True
            elif a > target:
                large = column - 1
            else:
                small = column + 1
                    
            if small > large:
                return False
        