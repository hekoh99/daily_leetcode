class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        vector<int> closes;
        for(int i=0;i<s.length();i++) {
            if (s[i] == '[') {
                closes.push_back(i);
            }
            else if (closes.empty()) {
                ans++;
            }
            else {
                closes.pop_back();
            }
        }
        return (ans + 1) / 2;
    }
};