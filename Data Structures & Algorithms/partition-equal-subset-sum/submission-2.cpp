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
        int totalSum = 0;
        for (int n : nums) totalSum += n;

        // If sum is odd, we can't partition into two equal integers
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;

        // bitset<MAX_POSSIBLE_SUM>
        // bits[i] will be 1 if sum 'i' is reachable
        std::bitset<10001> bits(1); // bit 0 is 1 (sum 0 is always reachable)

        for (int n : nums) {
            // This single line replaces your entire DFS.
            // It shifts all reachable sums by 'n' and ORs them with previous sums.
            bits |= (bits << n);
        }

        return bits[target];
    }
};
