class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        int accumXOR = 0;
        vector<int> charMap(26, 0);
        charMap['a' - 'a'] = 1;
        charMap['e' - 'a'] = 2;
        charMap['i' - 'a'] = 4;
        charMap['o' - 'a'] = 8;
        charMap['u' - 'a'] = 16;

        vector<int> XORHistory(32, -1);
        for(int i=0;i<s.length();i++) {
            accumXOR ^= charMap[s[i] - 'a'];
            if (XORHistory[accumXOR] == -1 && accumXOR != 0) {
                XORHistory[accumXOR] = i;
            }
            if (ans < i - XORHistory[accumXOR]) {
                ans = i - XORHistory[accumXOR];
            }
        }

        return ans;
    }
};