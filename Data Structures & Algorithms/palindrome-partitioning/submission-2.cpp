class Solution {
public:
    void dfs(vector<vector<string>>& res, vector<string>& splits, string& s, int i, int startCurr, int totalLen) {
        if (i >= s.size()) {
            if (totalLen == s.size()) res.push_back(splits);
            return;
        }

        vector<string> tempSplits(splits.begin(), splits.end());
        dfs(res, splits, s, i + 1, startCurr, totalLen);
        
        splits = vector<string>(tempSplits.begin(), tempSplits.end());
        int endIter = ((i + startCurr) / 2) - startCurr;
        bool isPalindrome = true;

        for (int j = 0; j <= endIter; j++) {
            if (s[startCurr + j] != s[i - j]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            int newStrLength = i + 1 - startCurr;
            splits.push_back(s.substr(startCurr, newStrLength));
            dfs(res, splits, s, i + 1, i + 1, totalLen + newStrLength);
        }
    }

    vector<vector<string>> partition(string s) {
        int strLen = s.size();
        vector<vector<string>> res {};
        vector<string> splits {};

        dfs(res, splits, s, 0, 0, 0);

        return res;
    }
};
