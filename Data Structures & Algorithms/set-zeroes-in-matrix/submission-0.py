class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        # Saving init zeroes and assigning zeroes by row
        for row in range(len(matrix)):
            foundZero = False
            col = 0

            while col < len(matrix[0]):
                if matrix[row][col] == 0:
                    matrix[row][col] = 'a'

                    if not foundZero:
                        foundZero = True
                        col = -1
                elif foundZero and (matrix[row][col] != 'a'):
                    matrix[row][col] = 0

                col += 1
        
        # Assigning zeroes by column
        for col in range(len(matrix[0])):
            foundZero = False
            row = 0

            while row < len(matrix):
                if foundZero:
                    matrix[row][col] = 0
                elif matrix[row][col] == 'a':
                    if not foundZero:
                        foundZero = True
                        row = -1

                row += 1