class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int insertIdx = 0;
        vector<int> res{};
        res.reserve(k);
        
        for (int i = 0; i < arr.size(); i++) {            
            if (arr[i] >= x) break;
            insertIdx++;
        }

        if (insertIdx == 0) {
            res = vector<int>(arr.begin(), arr.begin() + k);
            return res;
        } else if (insertIdx == arr.size()) {
            res = vector<int>(arr.begin() + arr.size() - k, arr.begin() + arr.size());
            return res;
        }

        int left = max(insertIdx - 1, 0);
        int right = min(left + 1, static_cast<int>(arr.size() - 1));
        int i = 0;

        while (i < k) {
            cout << "left: " << left << endl;
            cout << "right: " << right << endl;
            if (left < 0) {
                res.push_back(arr[right]);
                right++;
                i++;
                continue;
            } else if (right >= arr.size()) {
                res.push_back(arr[left]);
                left--;
                i++;
                continue;
            }

            int leftDiff = abs(arr[left] - x);
            int rightDiff = abs(arr[right] - x);
            
            if (leftDiff <= rightDiff) {
                res.push_back(arr[left]);
                left--;
            } else {
                res.push_back(arr[right]);
                right++;
            }

            i++;
        }

        sort(res.begin(), res.end());

        return res;
    }
};