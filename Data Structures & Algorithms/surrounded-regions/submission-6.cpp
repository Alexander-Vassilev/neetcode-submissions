class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        int width = board[0].size();
        vector<vector<bool>> seen(height, vector<bool>(width, false));
        vector<vector<int>> groupCoords;
        groupCoords.reserve(height * width);
        stack<vector<int>> st;
        vector<int> deltaR = {{1, 0, -1, 0}};
        vector<int> deltaC = {{0, 1, 0, -1}};
        vector<vector<int>> path{};
        
        for (int i = 0; i < width - 1; i++) {
            path.push_back({0, i});
            path.push_back({height - 1, width - i - 1});
        }

        for (int i = 0; i < height - 1; i++) {
            path.push_back({i, width - 1});
            path.push_back({height - i - 1, 0});
        }

        for (auto& tile : path) {
            int row = tile[0], col = tile[1];
            if (board[row][col] == 'X' || seen[row][col]) continue;

            st.push({row, col});
            seen[row][col] = true;

            while (!st.empty()) {
                vector<int> coords = st.top();
                groupCoords.push_back(coords);
                int r = coords[0];
                int c = coords[1];
                st.pop();
                //cout << "visting tile " << r << " " << c << endl;

                for (int i = 0; i < 4; i++) {
                    int newR = r + deltaR[i];
                    int newC = c + deltaC[i];
                    //cout << "exploring " << newR << " " << newC << endl;
                    bool rInBounds = newR >= 0 && newR < height;
                    bool cInBounds = newC >= 0 && newC < width;
                    bool inBounds = rInBounds && cInBounds;

                    if (inBounds) {
                        if (board[newR][newC] == 'O' && !seen[newR][newC]) {
                            //cout << "adding tile" << endl;
                            vector<int> newCoords {newR, newC};
                            seen[newR][newC] = true;
                            st.push(newCoords);
                        }
                    }
                }
            }

            for (auto& cell : groupCoords) {
                board[cell[0]][cell[1]] = 'S';
            }

            groupCoords = {};
            groupCoords.reserve(height * width);
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                switch(board[i][j]) {
                    case 'S':
                        board[i][j] = 'O';
                        break;
                    case 'O':
                        board[i][j] = 'X';
                        break;
                    default:
                        break;
                }
            }
        }
    }
};
