class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        vector<int> dp(1001, 0);

        for(int i=2;i <= 1000;i++) {
            if (dp[i] == 0) {
                dp[i] = i;
            }
            for(int j=2;j * i <= 1000;j++) {
                dp[j * i] = dp[i] + j;
            }
        }
        return dp[n];
    }
};