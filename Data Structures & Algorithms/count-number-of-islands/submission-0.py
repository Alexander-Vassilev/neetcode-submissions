class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        seenMatrix = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        stack = []
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        numIslands = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j] == "1") and not seenMatrix[i][j]:
                    stack.append((i, j))
                    numIslands += 1

                    while stack:
                        y = stack[-1][0]
                        x = stack[-1][1]
                        seenMatrix[y][x] = True
                        stack.pop()

                        for direction in dirs:
                            newY, newX = y + direction[0], x + direction[1]
                            
                            yInBounds = (0 <= newY) and (newY < len(grid))
                            xInBounds = (0 <= newX) and (newX < len(grid[0]))

                            if yInBounds and xInBounds:
                                isLand = False

                                if grid[newY][newX] == "1":
                                    isLand = True

                                if (not seenMatrix[newY][newX]) and isLand:
                                    stack.append((newY, newX))
        
        return numIslands
                        
