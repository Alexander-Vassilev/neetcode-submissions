class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        struct Tile {
            int row = 0;
            int col = 0;
            //int srcDir = 0; // (-1 = N/A, 0 = left, 1 = up, 2 = right, 3 = down)
            set<vector<int>> seen;
            int idx = 0;
        };

        int height = board.size();
        int width = board[0].size();
        int wordLen = word.size();
        // row, col, src dir (-1 = N/A, 0 = left, 1 = up, 2 = right, 3 = down), idx
        stack<Tile> st;
        vector<int> dR = {0, -1, 0, 1};
        vector<int> dC = {-1, 0, 1, 0};
        vector<int> oppositeDirs = {2, 3, 0, 1};
 
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0]) st.push({i, j, {}, 0});    

                while (!st.empty()) {
                    Tile tile = st.top();
                    st.pop();
                    if (tile.idx == wordLen - 1) return true;
                    int newIdx = tile.idx + 1;
                    tile.seen.insert({tile.row, tile.col});

                    for (int k = 0; k < 4; k++) {
                        int newR = tile.row + dR[k];
                        int newC = tile.col + dC[k];
                        vector<int> newCoords {newR, newC};
                        bool rValid = newR >= 0 && newR < height;
                        bool cValid = newC >= 0 && newC < width;
                        bool valid = rValid && cValid;

                        if (valid && board[newR][newC] == word[newIdx] && !tile.seen.contains(newCoords)) {
                            st.push({newR, newC, tile.seen, newIdx});
                        }
                    }
                }
            }
        }

        return false;
    }
};