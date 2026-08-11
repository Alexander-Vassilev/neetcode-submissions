class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> storage {};
        vector<int> res(len);

        for (int i = 0; i < len; i++) {
            if (storage.empty() || temperatures[storage.top()] >= temperatures[i]) {
                storage.push(i);
            } else {
                while (!storage.empty() && temperatures[storage.top()] < temperatures[i]) {
                    int topEl = storage.top();
                    res[topEl] = i - topEl;
                    storage.pop();
                }

                storage.push(i);
            }
        }

        return res;
    }
};
