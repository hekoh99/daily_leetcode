class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int alphaUpper[26] = {0,};
        int alphaLower[26] = {0,};
        for(int i=0;i<s.size();i++) {
            if (isupper(s[i])) {
                alphaUpper[s[i] - 'A']++;
            }
            else {
                alphaLower[s[i] - 'a']++;
            }
        }
        int odd = 0;
        int even = 0;
        for(int i=0;i<26;i++) {
            even += alphaUpper[i] / 2;
            alphaUpper[i] = alphaUpper[i] % 2;
            
            even += alphaLower[i] / 2;
            alphaLower[i] = alphaLower[i] % 2;
            
            if (alphaUpper[i] > 0 || alphaLower[i] > 0) {
                odd++;
            }
        }
        ans = even * 2;
        if (odd > 0) {
            ans += 1;
        }
        return ans;
    }
};