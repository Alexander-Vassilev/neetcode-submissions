class Solution {
public:
    int dfs(vector<int>& coins, vector<int>& memo, int amount, int currValue, int currNumSteps) {
        int ret = 1e9;

        if (currValue > amount) {
            return 1e9;
        } else if (memo[currValue] <= currNumSteps) {
            return 1e9;
        }

        memo[currValue] = currNumSteps;
            
        if (currValue == amount) return min(currNumSteps, memo[amount]);

        for (auto& coin : coins) {
            int remaining = INT_MAX - coin;

            if (currValue <= remaining) {
                ret = min(ret, dfs(coins, memo, amount, currValue + coin, currNumSteps + 1));
            }
        }

        return ret;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        vector<int> memo(amount + 1, 1e9);

        int ret = dfs(coins, memo, amount, 0, 0);

        if (ret == 1e9) return -1;

        return ret;
    }
};
