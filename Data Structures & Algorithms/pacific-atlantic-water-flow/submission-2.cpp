class Solution {
vector<int> dR = {{0, 1, 0, -1}};
vector<int> dC = {{1, 0, -1, 0}};    

public:
    void dfs(vector<vector<bool>>& seen, set<vector<int>>& oceanSet, vector<int>& tile, int height, int width, vector<vector<int>>& heights, stack<vector<int>>& st) {
        if (seen[tile[0]][tile[1]]) return;

        seen[tile[0]][tile[1]] = true;
        st.push(tile);

        while (!st.empty()) {
            vector<int> cell = st.top();
            oceanSet.insert(cell);
            int r = cell[0];
            int c = cell[1];
            //cout << "inserting " << r << " " << c << endl;
            int currHeight = heights[r][c];
            st.pop();

            for (int i = 0; i < 4; i++) {
                int newR = r + dR[i];
                int newC = c + dC[i];
                bool rInBounds = newR >= 0 && newR < height;
                bool cInBounds = newC >= 0 && newC < width;
                bool inBounds = rInBounds && cInBounds;

                if (inBounds && !seen[newR][newC] && heights[newR][newC] >= currHeight) {
                    st.push({newR, newC});
                    seen[newR][newC] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int height = heights.size();
        int width = heights[0].size();
        vector<vector<int>> ret;
        set<vector<int>> pacificSet;
        set<vector<int>> atlanticSet;
        ret.reserve(height * width);
        vector<vector<int>> indicesExplore;
        vector<vector<bool>> seen(height, vector<bool>(width, false));
        stack<vector<int>> st;
        
        for (int i = 0; i < width; i++) {
            indicesExplore.push_back({0, i});
        }

        for (int i = 1; i < height; i++) {
            indicesExplore.push_back({i, 0});
        }

        //cout << endl;
        //cout << endl;

        for (auto& tile : indicesExplore) {
            //cout << "edge tile: " << tile[0] << " " << tile[1] << endl;
            dfs(seen, pacificSet, tile, height, width, heights, st);
        }

        //cout << endl;
        //cout << endl;
        indicesExplore = {};
        seen = vector<vector<bool>>(height, vector<bool>(width, false));

        for (int i = 0; i < width; i++) {
            indicesExplore.push_back({height - 1, i});
        }

        for (int i = 0; i < height - 1; i++) {
            indicesExplore.push_back({i, width - 1});
        }

        for (auto& tile : indicesExplore) {
            //cout << "edge tile: " << tile[0] << " " << tile[1] << endl;
            dfs(seen, atlanticSet, tile, height, width, heights, st);
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                vector<int> coords = {i, j};
                if (pacificSet.contains(coords) && atlanticSet.contains(coords)) {
                    ret.push_back(coords);
                }
            }
        }

        return ret;
    }
};