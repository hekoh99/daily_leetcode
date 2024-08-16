class Solution {
private:
    vector<vector<string>> ans;

private:
    bool isPalindrome(string s) {
        int res = true;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                res = false;
                break;
            }
            start++;
            end--;
        }
        return res;
    }

    void setPalindrome(string& s, int index, vector<string>& sub) {
        if (s.length() == index) {
            ans.push_back(sub);
            return ;
        }
        string candidate;
        for(int i=index;i<s.length();i++) {
            candidate = s.substr(index, i - index + 1);
            if (isPalindrome(candidate)) {
                sub.push_back(candidate);
                setPalindrome(s, i + 1, sub);
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> sub;
        setPalindrome(s, 0, sub);
        return ans;
    }
};