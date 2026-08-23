class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stParen;
        deque<int> stAstr;
        int len = s.size();
        int i = 0;

        for (int i = 0; i < len; i++) {
            char c = s[i];

            switch (c) {
                case '(':
                    stParen.push(i);

                    break;
                case ')':
                    if (!stParen.empty()) {
                        stParen.pop();
                    } else if (!stAstr.empty()) {
                        stAstr.pop_back();
                    } else {
                        return false;
                    }

                    break;
                default:
                    stAstr.push_front(i);

                    break;
            }
        }

        while (!stParen.empty()) {
            int i = stParen.top();

            if (stAstr.empty() || i > stAstr.front()) return false;

            stAstr.pop_front();
            stParen.pop();
        }

        return true;
    }
};
