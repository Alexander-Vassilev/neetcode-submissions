class Solution {
public:
    vector<string> dfs(int n, int numOpen, int numClosed, string curr) {
        vector<string> res {};

        if (numOpen < n) {
            string newOpen = curr + '(';
            res = dfs(n, numOpen + 1, numClosed, newOpen);
        }
        
        if (numClosed < n && numOpen > numClosed) {
            string newClosed = curr + ')';
            vector<string> closingRes = dfs(n, numOpen, numClosed + 1, newClosed);
            res.insert(res.end(), closingRes.begin(), closingRes.end());
        }

        if (res.empty()) return {curr};

        return res;
    }

    vector<string> generateParenthesis(int n) {
        return dfs(n, 0, 0, "");
    }
};
