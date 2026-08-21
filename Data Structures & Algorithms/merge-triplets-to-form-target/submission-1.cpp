class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> foundIdces(3, false);
        vector<bool> check(3, false);
        int j = 0;

        for (auto& triplet : triplets) {
            //cout << "iteration " << j << endl;
            bool cand = false;

            for (int i = 0; i < 3; i++) {
                if (triplet[i] == target[i]) {
                    //cout << "el " << i << " matches" << endl;
                    cand = true;
                    check[i] = true;
                }
            }

            if (cand) {
                for (int i = 0; i < check.size(); i++) {
                    if (triplet[i] > target[i]) {
                        cand = false;
                        break;
                    }
                }
            }

            if (cand) {
                for (int i = 0; i < 3; i++) {
                    if (check[i]) {
                        //cout << "checked off: " << i << endl;
                        foundIdces[i] = true;
                    } else if (foundIdces[i] == false) {
                        cand = false;
                    }                        
                }
            }

            if (cand) return true;
            j++;

            for (int i = 0; i < 3; i++) check[i] = false;
        }

        return false;
    }
};
