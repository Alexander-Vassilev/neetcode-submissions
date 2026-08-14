class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ret = 1;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            int num = nums[i];

            if ((num > 0) && (num <= len) && (num != i + 1)) {
                while (true) {
                    int temp = nums[num - 1];
                    //if (temp == num) num = 0;
                    nums[num - 1] = num;
                    if (temp <= 0 || temp > len || temp == num) break;
                    num = temp;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return len + 1;
    }
};