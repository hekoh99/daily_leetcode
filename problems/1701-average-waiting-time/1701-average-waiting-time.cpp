class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long timeSum = 0;
        long long currentTime = 0;
        for(int i=0;i<customers.size();i++) {
            if (currentTime < customers[i][0]) {
                currentTime = customers[i][0];
            }
            currentTime += customers[i][1];
            timeSum += (currentTime - customers[i][0]);
        }
        return (double) timeSum / (double) customers.size();
    }
};