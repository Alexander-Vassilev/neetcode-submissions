class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == val) {
                k--;
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }

        return k;
    }
};