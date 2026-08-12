class Solution {
public:
    set<vector<int>> dfs(vector<int>& nums, int target, vector<int> selections, int currSum, int searchStart) {
        set<vector<int>> retSet;
        
        for (int i = searchStart; i < nums.size(); i++) {
            int newSum = currSum + nums[i];

            if (newSum == target) {
                selections.push_back(nums[i]);
                retSet.insert(selections);

                return retSet;
            } else if (newSum < target) {
                selections.push_back(nums[i]);
                set<vector<int>> subset = dfs(nums, target, selections, newSum, i);
                retSet.insert(subset.begin(), subset.end());
                selections.pop_back();
            } else {
                return retSet;
            }

            newSum = currSum;
        }

        return retSet;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> selections {};
        set<vector<int>> retSet = dfs(nums, target, selections, 0, 0);
        vector<vector<int>> ret(retSet.begin(), retSet.end());

        return ret;
    }
};
