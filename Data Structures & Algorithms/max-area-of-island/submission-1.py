class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        islandSize = 0
        maxIslandSize = 0

        def dfs(row, col):
            nonlocal islandSize

            rowInBounds = (0 <= row) and (row < len(grid))
            colInBounds = (0 <= col) and (col < len(grid[0]))

            if rowInBounds and colInBounds:
                if grid[row][col] == 1:
                    islandSize += 1
                    grid[row][col] = 0

                    for direction in dirs:
                        newRow = row + direction[0]
                        newCol = col + direction[1]
                        dfs(newRow, newCol)

        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                dfs(i, j)
                maxIslandSize = max(islandSize, maxIslandSize)
                islandSize = 0
        
        return maxIslandSize