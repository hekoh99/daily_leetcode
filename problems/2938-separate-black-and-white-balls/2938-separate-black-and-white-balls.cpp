class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long blackNum = 0;
        long long whiteNum = 0;
        for(int i=0;i<s.length();i++) {
            if (s[i] == '1') {
                ans += blackNum * whiteNum;
                whiteNum = 0;
                blackNum++;
            }
            if (s[i] == '0') {
                whiteNum++;
            }
        }
        if (whiteNum > 0) {
            ans += blackNum * whiteNum;
        }
        return ans;
    }
};