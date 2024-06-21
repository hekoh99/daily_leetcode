class Solution {
private:
    int maxCostomers(vector<int>& cusSum, int minutes) {
        int max = cusSum[minutes - 1];
        for(int i=0;i<cusSum.size() - minutes;i++) {
            int tmp = cusSum[i + minutes] - cusSum[i];
            if (max < tmp) {
                max = tmp;
            }
        }
        return max;
    }
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        int sum = 0;
        vector<int> sumVec;
        for(int i=0;i<n;i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
                customers[i] = 0;
            }
            sum += customers[i];
            sumVec.push_back(sum);
        }
        ans += maxCostomers(sumVec, minutes);
        return ans;
    }
};