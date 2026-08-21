class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        uint8_t foundIdces = 0;
        //vector<bool> check(3, false);
        uint8_t check = 0;

        for (auto& triplet : triplets) {
            //cout << endl;
            //cout << "new iteration " << endl;
            bool cand = false;

            for (int i = 0; i < 3; i++) {
                if (triplet[i] == target[i]) {
                    //cout << "el " << i << " matches" << endl;
                    cand = true;
                    check |= (1 << i);
                    //cout << bitset<8>(check) << endl;
                }
            }

            if (cand) {
                for (int i = 0; i < 3; i++) {
                    if (triplet[i] > target[i]) {
                        cand = false;
                        break;
                    }
                }
            }

            if (cand) {
                for (int i = 0; i < 3; i++) {
                    if ((check >> i) & 1) {
                        //cout << "checked off: " << i << endl;
                        foundIdces |= (1 << i);
                        //cout << bitset<8>(foundIdces) << endl;
                    } else if (!((foundIdces >> i) & 1)) {
                        cand = false;
                    }                        
                }
            }

            if (cand) return true;

            check = 0;
        }

        return false;
    }
};
