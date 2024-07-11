class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        int n = s.length();
        for(int i=0;i<n;i++) {
            if (s[i] == ')') {
                int backIndex = ans.size() - 1;
                string tmp;
                while (ans[backIndex] != '(') {
                    tmp += ans[backIndex];
                    backIndex--;
                }
                ans = ans.substr(0, backIndex);
                ans.append(tmp);
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};