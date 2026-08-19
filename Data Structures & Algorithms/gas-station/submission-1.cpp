class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret = 0;
        int runningSum = 0;
        int j = 0;
        int currDistance = 0;
        int len = gas.size();

        for (int i = 0; i < len * 2; i++) {
            if (i == gas.size()) j = 0;
            
            runningSum += gas[j] - cost[j];
            //cout << "j: " << j << endl;
            //cout << "running sum: " << runningSum << endl;
            //cout << endl;
            j++;
            currDistance++;
            
            if (runningSum < 0) {
                ret = j;
                runningSum = 0;
                currDistance = 0;
            } else if (currDistance >= len) {
                return ret;
            }
        }

        return -1;
    }
};
