class Solution {
public:
    int getXorSum(int n) {
        int rem = n % 4;
        if (rem == 0) return n;
        if (rem == 1) return 1;
        if (rem == 2) return n + 1;
        return 0;
}

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalXor = getXorSum(n); // O(1) calculation
        
        int actualXor = 0;
        for (int x : nums) {
            actualXor ^= x;
        }
        
        return totalXor ^ actualXor;
    }
};
