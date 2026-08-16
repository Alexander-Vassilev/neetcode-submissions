class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int bestLength = 1;
        int bestIndex = 0;

        for (int i = 0; i < len; i++) {
            //cout << "character " << i << endl;
            int currLength = 1;
            int l = i;
            int validL = i;
            int r = i;
            bool isLimit = false;
            char ogChar = s[i];
            bool isSameChar = true;
            bool isOdd = true;
            //int k = 0;

            while (!isLimit && ((r - l) < (len - 1))) {
                //cout << endl;
                //cout << l << " " << r << endl;
                l--;
                r++;
                isLimit = true;
                bool leftInBounds = l >= 0;
                bool rightInBounds = r < len;

                if (leftInBounds && rightInBounds) {
                    if (s[l] == s[r]) {
                        currLength += 2;
                        validL = l;
                        //cout << "found both sides" << endl;
                        isLimit = false;
                    }
                }

                if (!isSameChar) continue;

                if (isSameChar && isLimit) {
                    if (leftInBounds && s[l] == s[r - 1]) {
                        //cout << "found on left" << endl;
                        currLength += 1;
                        validL = l;
                        r--;
                        isLimit = false;
                    } else if (rightInBounds && s[l + 1] == s[r]) {
                        //cout << "found on right" << endl;
                        currLength += 1;
                        l++;
                        isLimit = false;
                    }
                }

                if (!isLimit && !((s[l] == ogChar) && (s[r] == ogChar) && isSameChar)) {
                    isSameChar = false;
                    //cout << "not same char" << endl;
                }
            }

            if (currLength > bestLength) {
                bestLength = currLength;
                bestIndex = max(0, validL);
                //cout << "best length: " << currLength << endl;
                //cout << "best index: " << bestIndex << endl;
            }
        }

        //cout << "best length: " << bestLength << endl;
        //cout << "best index: " << bestIndex << endl;
        string ret(s.begin() + bestIndex, s.begin() + bestIndex + bestLength);
        //string ret = "";

        return ret;
    }
};
