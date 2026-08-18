class Solution {
public:
    void backtrack(vector<vector<string>>& ret, vector<string>& boardStr, vector<bool>& colTracker, vector<bool>& diagTracker, int n, int i) {
        if (i == n) {
            ret.push_back(boardStr);
            return;
        }
        
        for (int j = 0; j < n; j++) {
            if (colTracker[j]) continue;

            int diagIdx1 = (j - i) + n - 1;
            int diagOffset = 2 * n - 1;
            int diagIdx2 = ((n - j) - i) + n - 1 + diagOffset;

            if (diagTracker[diagIdx1] || diagTracker[diagIdx2]) continue;

            boardStr.push_back(string(n, '.'));
            boardStr[boardStr.size() - 1][j] = 'Q';
            colTracker[j] = true;
            diagTracker[diagIdx1] = true;
            diagTracker[diagIdx2] = true;

            backtrack(ret, boardStr, colTracker, diagTracker, n, i + 1);

            boardStr.pop_back();
            colTracker[j] = false;
            diagTracker[diagIdx1] = false;
            diagTracker[diagIdx2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> colTracker(n, false);
        vector<bool> diagTracker(4 * n - 2, false);
        vector<vector<string>> ret {};
        vector<string> boardStr {};

        backtrack(ret, boardStr, colTracker, diagTracker, n, 0);

        return ret;
    }
};
