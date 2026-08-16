class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bitMask = 1;
        uint32_t ret = 0;
        
        for (int i = 0; i < 31; i++) {
            ret |= (n & bitMask);
            ret <<= 1;
            cout << bitset<32>(ret) << endl;
            n >>= 1;
        }

        ret |= (n & bitMask);

        return ret;
    }
};
