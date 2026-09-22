class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<bool> seen(256, false);
        int maxLen = 0;
        int tail = 0;
        int length = s.size();

        for (int i = 0; i < length; i++) {
            int index = s[i];

            while (seen[index]) {
                seen[s[tail]] = false;
                tail++;
            }

            seen[index] = true;
            maxLen = max(maxLen, i - tail + 1);
        }

        return maxLen;
    }
};
