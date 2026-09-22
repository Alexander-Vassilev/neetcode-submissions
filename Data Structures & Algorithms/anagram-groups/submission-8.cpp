class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::vector<int>, std::vector<std::string>> retMap;
        std::vector<std::vector<std::string>> ret;
        
        for (auto& str : strs) {
            std::vector<int> charMap(26);

            for (char c : str) {
                charMap[c - 'a']++;
            }

            retMap[charMap].push_back(str);
        }

        for (auto& el : retMap) {
            ret.push_back(el.second);
        }

        return ret;
    }
};
