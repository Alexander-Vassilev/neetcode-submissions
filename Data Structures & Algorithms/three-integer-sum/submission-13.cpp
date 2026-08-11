class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res {};
        int len = nums.size();
        int el = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; i++) {
            //cout << "first el: " << nums[i] << "\n";
            //cout << "\n";
            if ((i != 0 && -nums[i] == el) || (nums[i] > 0)) continue;
            el = -nums[i];
            int left = i + 1;
            int right = len - 1;
            
            while (left < right) {
                //std::cout << left << std::endl;
                //std::cout << right << std::endl;
                cout << endl;

                bool isLeftIncr = false;
                int sum = nums[left] + nums[right];

                if (sum < el) {
                    isLeftIncr = true;
                } else if (sum > el) {
                    //right--;
                } else {
                    vector<int> entry {-el, nums[left], nums[right]};
                    res.push_back(entry);
                    isLeftIncr = true;
                }

                int newSum = sum;

                while (newSum == sum && left < right) {
                    //std::cout << "new sum" << std::endl;
                    //std::cout << left << std::endl;
                    //std::cout << right << std::endl;

                    isLeftIncr ? left++ : right--;
                    newSum = nums[left] + nums[right];
                }
            }
        }

        //std::cout << "res len: " << res.size() << std::endl;

        return res;
    }
};
