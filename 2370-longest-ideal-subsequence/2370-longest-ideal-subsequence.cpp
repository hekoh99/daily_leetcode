class Solution {
public:
    int longestIdealString(string s, int k) {
        int len = s.length();
        vector<int> alpha(26, 0);
        int cur = 0;
        int max = 0;
        int start;
        int end;

        for (int i=0;i<len;i++) {
            start = s[i] - k >= 'a' ? s[i] - k : 'a';
            end = s[i] + k <= 'z' ? s[i] + k : 'z';
            alpha[s[i] - 'a'] = *max_element(alpha.begin() + (start - 'a'), alpha.begin() + (end - 'a' + 1)) + 1;
            if (max < alpha[s[i] - 'a'])
            {
                max = alpha[s[i] - 'a'];
            }
        }
        return max;
    }
};