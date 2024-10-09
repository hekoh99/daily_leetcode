class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        vector<int> opens;
        for(int i=0;i<s.length();i++) {
            if (s[i] == '(') {
                opens.push_back(i);
            }
            else {
                if (opens.empty()) {
                    ans++;
                }
                else {
                    opens.pop_back();
                }
            }
        }
        ans += opens.size();
        return ans;
    }
};