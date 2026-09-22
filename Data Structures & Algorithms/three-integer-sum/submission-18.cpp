class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        int length = nums.size();
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < length; i++) {
            //std::cout << "new loop: " << i << "\n";
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = length - 1;

            while (l < r) {
                //std::cout << "l: " << l << "\n";
                //std::cout << "r: " << r << "\n";
                int curr = nums[i] + nums[l] + nums[r];

                if (curr == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && (nums[l + 1] == nums[l])) l++;
                    l++;
                } else if (curr > 0) {
                    while (l < r && (nums[r - 1] == nums[r])) r--;
                    r--;
                } else {
                    while (l < r && (nums[l + 1] == nums[l])) l++;
                    l++;
                }
            }
        }

        return ret;
    }
};

// -4, -1, -1, 0, 1, 2