class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        ret.reserve(2);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int temp = nums[i] + nums[j];

                if (temp == target) {
                    ret.push_back(i);
                    ret.push_back(j);

                    return ret;
                }
            }
        }
    }
};
