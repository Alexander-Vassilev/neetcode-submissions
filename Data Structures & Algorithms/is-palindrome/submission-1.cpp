class Solution {
public:
    bool isAlphaNumeric(char c) {
        return ((c - 'a') < 26 && (c >= 'a')) ||  
            ((c - 'A') < 26 && (c >= 'A')) || ((c - '0') < 10 && (c >= '0'));
    }

    bool isPalindrome(string s) {
        int caseDiff = 'a' - 'A';
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (!isAlphaNumeric(s[l]) && l < r) l++;
            while (!isAlphaNumeric(s[r]) && l < r) r--;

            if (s[l] >= 'a') s[l] -= caseDiff;
            if (s[r] >= 'a') s[r] -= caseDiff;
            if (s[l] != s[r]) return false;

            l++;
            r--;
        }

        return true;
    }
};
