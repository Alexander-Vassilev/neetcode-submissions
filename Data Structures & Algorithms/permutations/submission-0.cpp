class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path) {
        int n = nums.size();
        
        if (n <= 0) {
            res.push_back(path);
        }
        
        for (int i = 0; i < n; i++) {
            int newEl = nums[i];
            path.push_back(newEl);
            nums.erase(nums.begin() + i);
            dfs(res, nums, path);
            nums.insert(nums.begin() + i, newEl);
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{};
        vector<int> path{};

        dfs(res, nums, path);

        return res;
    }
};
