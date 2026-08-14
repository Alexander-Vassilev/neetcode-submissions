class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfits = 0;
        int currStock = -1;
        int len = prices.size();

        for (int i = 0; i < len; i++) {
            if (((i == len - 1) || (prices[i + 1] < prices[i])) && currStock > -1) {
                totalProfits += prices[i] - currStock;
                currStock = -1;
            } else if ((i != len - 1) && prices[i + 1] > prices[i] && currStock == -1) {
                currStock = prices[i];
            }
        }

        return totalProfits;
    }
};