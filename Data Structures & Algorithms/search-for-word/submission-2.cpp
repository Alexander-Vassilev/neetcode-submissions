class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        if (i == word.size()) return true;
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[i]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '\0';
        int newI = i + 1;

        bool retVal = dfs(board, word, r + 1, c, newI) ||
                dfs(board, word, r - 1, c, newI) ||
                dfs(board, word, r, c + 1, newI) ||
                dfs(board, word, r, c - 1, newI);
        
        board[r][c] = temp;

        return retVal;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int height = board.size();
        int width = board[0].size();
 
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};