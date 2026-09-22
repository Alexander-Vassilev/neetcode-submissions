class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> retMap;
        std::vector<std::vector<std::string>> ret;
        
        for (auto& str : strs) {
            std::string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            retMap[sorted_str].push_back(str);
        }

        for (auto& el : retMap) {
            ret.push_back(el.second);
        }

        return ret;
    }
};
