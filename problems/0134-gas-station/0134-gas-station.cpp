class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curGas = 0;
        int startIndex = 0;
        int leftBehind = 0;
        for(int i=0;i<gas.size();i++) {
            curGas += (gas[i] - cost[i]);
            if (curGas < 0) {
                startIndex = i + 1;
                leftBehind += curGas;
                curGas = 0;
            }
        }
        if (curGas + leftBehind >= 0) {
            return startIndex;
        }
        return -1;
    }
};