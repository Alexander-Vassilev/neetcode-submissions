class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; i++) {
            int el = -nums[i];
            int left = i + 1;
            int right = len - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < el) {
                    left++;
                } else if (sum > el) {
                    right--;
                } else {
                    vector<int> entry {-el, nums[left], nums[right]};
                    res.insert(entry);
                    left++;
                }
            }
        }

        vector<vector<int>> resVec {res.begin(), res.end()};

        return resVec;
    }
};
