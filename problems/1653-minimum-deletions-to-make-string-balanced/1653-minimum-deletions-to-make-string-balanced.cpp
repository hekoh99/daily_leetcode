class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> dp(s.length());
        int bCount = 0;
        if (s[0] == 'b')
            bCount += 1;
        for(int i=1;i<s.size();i++) {
            if (s[i] == 'b') {
                bCount++;
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1] + 1 < bCount ? dp[i - 1] + 1 : bCount;
            }
        }
        return dp[s.size() - 1];
    }
};