class Solution {
    // 4-directional moves in a flat array (delta = dy * width + dx)
    // Up, Right, Down, Left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

public:
    void bfs(vector<vector<int>>& heights, vector<uint8_t>& reach, queue<int>& q, uint8_t bit) {
        int R = heights.size(), C = heights[0].size();
        
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            int r = curr / C, c = curr % C;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && 
                    !(reach[nr * C + nc] & bit) && 
                    heights[nr][nc] >= heights[r][c]) {
                    
                    reach[nr * C + nc] |= bit;
                    q.push(nr * C + nc);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size(), C = heights[0].size();
        vector<uint8_t> reach(R * C, 0);
        queue<int> q;

        // 1. Process Pacific (Bit 2: 0x10)
        for (int i = 0; i < R; i++) { q.push(i * C); reach[i * C] |= 2; }
        for (int j = 1; j < C; j++) { q.push(j); reach[j] |= 2; }
        bfs(heights, reach, q, 2);

        // 2. Process Atlantic (Bit 1: 0x01)
        for (int i = 0; i < R; i++) { q.push(i * C + (C - 1)); reach[i * C + (C - 1)] |= 1; }
        for (int j = 0; j < C - 1; j++) { q.push((R - 1) * C + j); reach[(R - 1) * C + j] |= 1; }
        bfs(heights, reach, q, 1);

        // 3. Final Collect
        vector<vector<int>> res;
        for (int i = 0; i < R * C; i++) {
            if (reach[i] == 3) res.push_back({i / C, i % C});
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int height = heights.size();
        int length = heights[0].size();
        vector<uint16_t> sourceCells{};
        vector<vector<bool>> pacificSeen(height, vector<bool>(length, false));
        vector<bool> atlanticSeen;
        vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<uint16_t> q;

        pacificSeen.reserve(height * length);
        atlanticSeen.reserve(height * length);
        uint16_t colMask = 0x00FF;

        for (int i = height; i > 0; i--) {
            int coord = (i << 8) | 0;
            pacificCells.push_back(coord);
        }

        for (int i = 0; i < heights[0].size(); i++) {
            int coord = i;
            pacificCells.push_back(coord);
        }

        for (auto& cell : pacificCells) {
            int row = cell[0];
            int col = cell[1];

            if (pacificSeen[row][col]) continue;

            uint16_t rowCol = (row << 8) | col;
            q.push(rowCol);

            while (!q.empty()) {
                rowCol = q.front();
                q.pop();
                row = rowCol >> 8;
                col = rowCol & colMask;
                pacificSeen[row][col] = true;
                int currHeight = heights[row][col];

                for (auto& dir : dirs) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    if (heights[newRow][newCol] >= currHeight) {
                        rowCol = (newRow << 8) | newCol;
                        q.push(rowCol);
                    }
                }
            }
        }
    }
};*/