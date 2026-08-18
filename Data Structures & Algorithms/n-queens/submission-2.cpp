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
            int diagIdx2 = ((4 * n - j) - i) - 2;

            if (diagTracker[diagIdx1] || diagTracker[diagIdx2]) continue;

            boardStr[i][j] = 'Q';
            colTracker[j] = true;
            diagTracker[diagIdx1] = true;
            diagTracker[diagIdx2] = true;

            backtrack(ret, boardStr, colTracker, diagTracker, n, i + 1);

            boardStr[i][j] = '.';
            colTracker[j] = false;
            diagTracker[diagIdx1] = false;
            diagTracker[diagIdx2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> colTracker(n, false);
        vector<bool> diagTracker(4 * n - 2, false);
        vector<vector<string>> ret {};
        vector<string> boardStr(n, string(n, '.'));

        backtrack(ret, boardStr, colTracker, diagTracker, n, 0);

        return ret;
    }
};
