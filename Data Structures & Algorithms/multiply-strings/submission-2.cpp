class Solution {
public:
    string multiply(string num1, string num2) {
        int num1Len = num1.size();
        int num2Len = num2.size();
        int totLen = num1Len + num2Len;
        vector<uint8_t> a(totLen, 0);
        vector<uint8_t> b(totLen, 0);
        int iFlip = 0;
        
        for (int i = num1Len - 1; i >= 0; i--) {
            int val1 = num1[i] - '0';
            int jFlip = 0;
            uint8_t carry = 0;

            for (int j = num2Len - 1; j >= 0; j--) {
                int val2 = num2[j] - '0';    
                int temp = val1 * val2 + carry;
                uint8_t ones = temp % 10;
                int tens = (temp - ones) / 10;
                carry = tens;

                a[totLen - 1 - jFlip - iFlip] = ones;
                jFlip++;
            }

            a[totLen - 1 - jFlip - iFlip] = carry;
            for (int j = 0; j < totLen; j++) {
                //cout << static_cast<int>(a[j]) << " ";
            }
            //cout << endl;
            for (int j = 0; j < totLen; j++) {
                //cout << static_cast<int>(b[j]) << " ";
            }
            carry = 0;
            //cout << endl;
            for (int j = totLen - 1; j >= 0; j--) {
                int temp = b[j] + a[j] + carry;
                uint8_t ones = temp;
                carry = 0;

                if (temp >= 10) {
                    carry = 1;
                    ones -= 10;
                }

                b[j] = ones;
            }

            //cout << endl;

            fill(a.begin(), a.end(), 0);
            iFlip++;
        }

        string ret = "";
        bool started = false;

        for (int i = 0; i < totLen; i++) {
            if (b[i] != 0) started = true;

            if (started) {
                char c = b[i] + '0';
                ret += c;
            }
        }

        if (ret.size() == 0) return "0";
        return ret;
    }
};
