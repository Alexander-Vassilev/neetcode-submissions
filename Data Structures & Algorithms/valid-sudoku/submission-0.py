class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        #check for rows
        for i in range(9):
            seenSet = {10}

            for j in range(9):
                if board[i][j] == ".":
                    continue
                elif board[i][j] in seenSet:
                    return False
                else:
                    seenSet.add(board[i][j])
        
        #check for columns
        for i in range(9):
            seenSet = {10}

            for j in range(9):
                if board[j][i] == ".":
                    continue
                elif board[j][i] in seenSet:
                    return False
                else:
                    seenSet.add(board[j][i])
        
        #check for cells
        for i in range(3):
            for j in range(3):
                topLeftX = i * 3
                topLeftY = j * 3
                seenSet = {10}

                for k in range(3):
                    for l in range(3):
                        if board[topLeftX + k][topLeftY + l] == ".":
                            continue
                        elif board[topLeftX + k][topLeftY + l] in seenSet:
                            return False
                        else:
                            seenSet.add(board[topLeftX + k][topLeftY + l])
        
        return True
                    