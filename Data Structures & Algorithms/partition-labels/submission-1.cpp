class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ret{};
        int big = 1e9;
        vector<pair<int, int>> charRanges(26, pair<int, int>{big, big});
        int len = s.size();

        for (int i = 0; i < len; i++) {
            int idx = s[i] - 'a';
            
            if (charRanges[idx].first == 1e9) {
                charRanges[idx].first = i;
            }

            charRanges[idx].second = i;
        }

        sort(charRanges.begin(), charRanges.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        int start = charRanges[0].first;
        int end = charRanges[0].second;

        for (auto& r : charRanges) {
            if (r.first == big) break;

            //cout << "range start: " << r.first << endl;
            //cout << "range end: " << r.second << endl;
            //cout << "start: " << start << endl;
            //cout << "end: " << end << endl;

            if (r.first > end) {
                //cout << "adding range" << endl;
                ret.push_back(end - start + 1);
                start = r.first;
                end = r.second;
            } else {
                end = max(end, r.second);
            }

            //cout << "\n";
        }

        ret.push_back(end - start + 1);

        return ret;
    }
};
