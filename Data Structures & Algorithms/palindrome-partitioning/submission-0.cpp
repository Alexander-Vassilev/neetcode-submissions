class Solution {
public:
    void dfs(vector<vector<string>>& res, vector<string>& splits, string& s, int i, int startCurr, int totalLen) {
        if (i >= s.size()) {
            if (totalLen == s.size()) res.push_back(splits);
            return;
        }

        //cout << endl;
        //cout << "numSplits: " << splits.size() << endl;;

        vector<string> tempSplits(splits.begin(), splits.end());
        
        dfs(res, splits, s, i + 1, startCurr, totalLen);

        splits = vector<string>(tempSplits.begin(), tempSplits.end());
        int endIter = ((i + startCurr) / 2) - startCurr;
        bool isPalindrome = true;

        //cout << "start: " << startCurr << endl;
        //cout << "end: " << i << endl;

        for (int j = 0; j <= endIter; j++) {
            //cout << "loop iter: " << j << endl;
            //cout << "left index: " << (startCurr + j) << endl;
            //cout << "right index: " << (i - j) << endl;
            if (s[startCurr + j] != s[i - j]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            int newStrLength = i + 1 - startCurr;
            //cout << "palindrome found: " << s.substr(startCurr, newStrLength) << endl;
            //cout << "palindrome start: " << startCurr << " palindrome end: " << (i + 1) << endl;
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
