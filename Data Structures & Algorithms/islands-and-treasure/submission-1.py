class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    stack = [(i, j, 0)]
                    seen = [[False for j in range(len(grid[0]))] for i in range(len(grid))]

                    while stack:
                        cell = stack.pop()
                        seen[cell[0]][cell[1]] = True
                        grid[cell[0]][cell[1]] = min(grid[cell[0]][cell[1]], cell[2])

                        for k in range(4):
                            x = [1, 0, -1, 0]
                            y = [0, -1, 0, 1]
                            row = cell[0] + y[k]
                            col = cell[1] + x[k]

                            if not ((0 <= row < len(grid)) and (0 <= col < len(grid[0]))):
                                continue

                            newDistance = cell[2] + 1

                            if (grid[row][col] > 0) and (newDistance < grid[row][col]):
                                stack.append((row, col, newDistance))
                    

#[inf,inf,inf]
#[inf, -1,inf]
#[0  ,inf,inf]

#[2, 3, 4]
#[1,-1, 5]
#[0, 1, 6]]

#sol = Solution()
#sol.islandsAndTreasure([[1, 0, 4], [2, 3, 4]])