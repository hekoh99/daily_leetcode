class Solution {
public:
    string shortestPalindrome(string s) {
        string ans;
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        for(int i=0;i<s.size();i++) {
            if (strncmp(s.c_str(), reversed.c_str() + i, s.size() - i) == 0) {
                return reversed.substr(0, i) + s;
            }
        }
        return reversed + s;
    }
};