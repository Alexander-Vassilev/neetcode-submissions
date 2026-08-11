class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        temp = 0

        # Init Left Column
        for i in range(len(matrix)):
            self.matrix[i][0] += temp
            temp = self.matrix[i][0]
        
        temp = 0

        # Init Right Column
        for i in range(len(matrix[0])):
            self.matrix[0][i] += temp
            temp = self.matrix[0][i]

        # Init Rest of Matrix
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                topContribution = self.matrix[i - 1][j]
                leftContribution = self.matrix[i][j - 1]
                diagContribution = self.matrix[i - 1][j - 1]
                self.matrix[i][j] += leftContribution + topContribution - diagContribution

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        res = self.matrix[row2][col2]
        
        if row1 == 0 and col1 == 0:
            return res
        elif row1 == 0:
            return res - self.matrix[row2][col1 - 1]
        elif col1 == 0:
            return res - self.matrix[row1 - 1][col2]
        else:
            return res - self.matrix[row1 - 1][col2] - self.matrix[row2][col1 - 1] + self.matrix[row1 - 1][col1 - 1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)