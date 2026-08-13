class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;

        int currLen = arr[0] == arr[1] ? 1 : 2;
        int maxLen = currLen;
        bool prevSign = arr[0] > arr[1];

        for (int i = 1; i < arr.size() - 1; i++) {
            bool currSign = arr[i] > arr[i + 1];

            if (currSign != prevSign) {
                currLen++;
            } else if (arr[i] == arr[i + 1]) {
                currLen = 1;
            } else {
                currLen = 2;
            }
            
            cout << currSign << ", " << currLen << endl;

            prevSign = currSign;
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};