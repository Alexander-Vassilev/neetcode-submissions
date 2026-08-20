class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();

        if (len % groupSize != 0) return false;

        map<int, int> cards;
        int numGroups = 0;
        const int maxGroups = len / groupSize;
        int currNumElements = 0;
        int currVal = -1;

        for (auto card : hand) {
            cards[card]++;
        }

        while (true) {
            bool foundHand = false;
            //cout << endl;
            //cout << "New loop" << endl;
            for (auto& el : cards) {
                //cout << "cur card" << el.first << endl;
                //cout << "cur val: " << currVal << endl;

                if ((el.second > 0) && (currVal == -1 || el.first == currVal + 1)) {
                    //cout << "inserting" << endl;
                    currNumElements++;
                    currVal = el.first;
                    el.second--;
                }

                if (currNumElements == groupSize) {
                    currVal = -1;
                    currNumElements = 0;
                    numGroups++;
                    foundHand = true;

                    if (numGroups == maxGroups) return true;

                    break;
                }
            }

            if (!foundHand) return false;
        }
    }
};
