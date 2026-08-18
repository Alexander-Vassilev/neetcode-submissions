class Solution {
public:
    void backtrack(vector<string>& ret, vector<string>& numCharMap, string& curr, string& digits, int i) {
        if (i >= digits.size()) {
            ret.push_back(curr);
            return;
        }
        
        int currDigit = digits[i] - 50;

        for (char c : numCharMap[currDigit]) {
            curr += c;
            backtrack(ret, numCharMap, curr, digits, i + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() < 1) return {};
        vector<string> ret {};
        vector<string> numCharMap(8, "");
        string curr = "";
        numCharMap[0] = "abc";
        numCharMap[1] = "def";
        numCharMap[2] = "ghi";
        numCharMap[3] = "jkl";
        numCharMap[4] = "mno";
        numCharMap[5] = "pqrs";
        numCharMap[6] = "tuv";
        numCharMap[7] = "wxyz";

        backtrack(ret, numCharMap, curr, digits, 0);

        return ret;
    }
};
