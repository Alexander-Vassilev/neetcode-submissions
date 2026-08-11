#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams = {};
        vector<vector<string>> ret = {};

        for (auto& el : strs) {
            string copyEl = el;
            std::sort(copyEl.begin(), copyEl.end());
            anagrams[copyEl].push_back(el);
        }

        for (auto& grams : anagrams) {
            ret.push_back(grams.second);
        }

        return ret;
    }
};
