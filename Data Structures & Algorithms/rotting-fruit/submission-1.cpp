class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int minutes = 0;
        uint16_t jMask = 0x0F;
        uint16_t iMask = 0xF0;
        uint16_t ijMask = 0xFF;
        queue<uint16_t> q;
        vector<bool> seenSet(256, false);
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    count++;
                }
                
                if (grid[i][j] == 2) {
                    //cout << i << " " << j << endl;
                    uint16_t data = (i << 4) | j;
                    q.push(data);
                }
            }
        }

        while (count > 0 && !q.empty()) {
            uint16_t data = q.front();
            q.pop();
            int i = (data & iMask) >> 4;
            int j = data & jMask;
            int time = data >> 8;

            //cout << "i: " << i << " j: " << j << " time: " << time << endl;
            count--;
            minutes = max(time, minutes);
            time++;

            for (auto& dir : dirs) {
                int newI = i + dir[0];
                int newJ = j + dir[1];
                bool iSafe = 0 <= newI && newI < grid.size();
                bool jSafe = 0 <= newJ && newJ < grid[0].size();
                uint16_t data = (newI << 4) | newJ;
                bool isSeen = seenSet[data];

                if (iSafe && jSafe && grid[newI][newJ] == 1 && !isSeen) {
                    seenSet[data & ijMask] = true;
                    data |= (time << 8);
                    q.push(data);
                }
            }
        }

        int retVal = count > 0 ? -1 : minutes;
        
        return retVal;
    }
};
