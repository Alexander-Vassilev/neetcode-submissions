class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<int>& path, int currSum, int searchStart, set<vector<int>>& ret) {
        int candidate = 0;
        
        for (int i = searchStart; i < candidates.size(); i++) {
            if (candidates[i] == candidate) continue;
            candidate = candidates[i];
            int newSum = currSum + candidate;

            if (newSum == target) {
                path.push_back(candidate);
                ret.insert(path);
                path.pop_back();

                return;
            } else if (newSum < target) {
                path.push_back(candidate);
                //candidates.erase(candidates.begin() + i);
                dfs(candidates, target, path, newSum, i + 1, ret);
                //candidates.insert(candidates.begin() + i, candidate);
                path.pop_back();
            } else {
                return;
            }

            newSum = currSum;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path{};
        set<vector<int>> retSet{};
        path.reserve(100);

        dfs(candidates, target, path, 0, 0, retSet);

        vector<vector<int>> ret{};
        ret.reserve(retSet.size());
        ret.assign(make_move_iterator(retSet.begin()), make_move_iterator(retSet.end()));

        return ret;
    }
};
