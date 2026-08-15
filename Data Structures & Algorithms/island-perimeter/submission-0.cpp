class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        int h = grid.size();
        int w = grid[0].size();
        vector<int> dr {0, 1, 0, -1};
        vector<int> dc {1, 0, -1, 0};
        queue<vector<int>> q;
        vector<vector<bool>> seen(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    seen[i][j] = true;
                    break;
                }
            }
        }

        int count = 0;

        while (!q.empty()) {
            count++;
            vector<int> coords = q.front();
            q.pop();
            int r = coords[0];
            int c = coords[1];

            cout << "num tiles: " << count << endl;
            cout << "r: " << r << endl;
            cout << "c: " << c << endl;

            for (int i = 0; i < 4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                bool rInBounds = 0 <= newR && newR < h;
                bool cInBounds = 0 <= newC && newC < w;
                bool inBounds = rInBounds && cInBounds;

                if (inBounds) {
                    if (grid[newR][newC] && !seen[newR][newC]) {
                        //cout << "pushing new tile: " << newR << ", " << newC << endl;
                        q.push({newR, newC});
                        seen[newR][newC] = true;
                    } else if (!grid[newR][newC]) {
                        cout << "pincr" << endl;
                        p++;
                    }
                } else {
                    cout << "pincr" << endl;
                    p++;
                }
            }
        }

        return p;
    }
};