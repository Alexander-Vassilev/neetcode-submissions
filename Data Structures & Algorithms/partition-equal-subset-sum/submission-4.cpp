class Solution {
public:
    bool dfs (map<map<int, int>, bool>& isValid, map<int, int>& totalNums, int currSum, const int sum) {
        if (currSum == sum) {
            return true;
        } else if (currSum > sum) {
            return false;
        } else if (isValid.find(totalNums) != isValid.end() && !isValid[totalNums]) return false;

        for (auto& el : totalNums) {
            if (!el.second) continue;

            el.second--;
            currSum += el.first;

            if (dfs(isValid, totalNums, currSum, sum)) return true;

            el.second++;
            currSum-= el.first;
        }

        isValid[totalNums] = false;

        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        map<int, int> totalNums;

        for (auto n : nums) {
            sum += n;
            totalNums[n]++;
        }

        if (sum % 2 == 1) return false;

        sum /= 2;
        map<map<int, int>, bool> isValid;
        vector<int> remainingNums(nums.begin(), nums.end());

        return dfs(isValid, totalNums, 0, sum);
    }
};
