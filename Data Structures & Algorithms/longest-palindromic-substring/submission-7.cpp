class Solution {
public:
    pair<int, int> expand(int l, int r, string s, int len) {
        while (true) {
            bool lInBounds = l >= 0 && l < len;
            bool rInBounds = r >= 0 && r < len;
            
            if (lInBounds && rInBounds && s[l] == s[r]) {
                l--;
                r++;
            } else break;
        }

        l++;
        r--;
        
        return {l, r - l + 1};
    }

    string longestPalindrome(string s) {
        int len = s.size();
        int subStart = 0;
        int maxLen = 0;

        for (int i = 0; i < len; i++) {
            auto [oddStart, oddSize] = expand(i, i, s, len);

            if (oddSize > maxLen) {
                subStart = oddStart;
                maxLen = oddSize;
            }

            auto [evenStart, evenSize] = expand(i, i + 1, s, len);

            if (evenSize > maxLen) {
                subStart = evenStart;
                maxLen = evenSize;
            }
        }

        return s.substr(subStart, maxLen);
    }
};
