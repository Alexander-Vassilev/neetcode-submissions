class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Min possible open '('
        int high = 0; // Max possible open '('

        for (char c : s) {
            if (c == '(') {
                low++; 
                high++;
            } else if (c == ')') {
                low--; 
                high--;
            } else { // '*' case
                low--;  // Treat as ')'
                high++; // Treat as '('
            }

            // If max possible '(' is negative, even with '*' we can't balance
            if (high < 0) return false;

            // low cannot be negative (we can't have "negative" open parens)
            // If low becomes negative, we assume '*' was an empty string
            if (low < 0) low = 0;
        }

        // If it's possible to have exactly 0 open parens, it's valid
        return low == 0;
    }
};