class Solution {
public:
    void dfs(vector<int>& nums, int target, vector<int>& selections, int currSum, int searchStart, vector<vector<int>>& ret) {
        for (int i = searchStart; i < nums.size(); i++) {
            int newSum = currSum + nums[i];

            if (newSum == target) {
                selections.push_back(nums[i]);
                ret.push_back(selections);
                selections.pop_back();

                return;
            } else if (newSum < target) {
                selections.push_back(nums[i]);
                dfs(nums, target, selections, newSum, i, ret);
                selections.pop_back();
            } else {
                return;
            }

            newSum = currSum;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> selections {};
        vector<vector<int>> ret{};
        selections.reserve(30);

        dfs(nums, target, selections, 0, 0, ret);

        return ret;
    }
};
