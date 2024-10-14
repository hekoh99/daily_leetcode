class Solution {
private:
    bool isPermutation(vector<int> count, string target) {
        bool res = true;
        for(int i=0;i<target.length();i++) {
            if(count[target[i] - 'a'] > 0) {
                count[target[i] - 'a']--;
            }
            else {
                res = false;
                break;
            }
        }
        return res;
    }
public:
    bool checkInclusion(string s1, string s2) {
        bool ans = false;
        vector<int> count(26, 0);
        for(int i=0;i<s1.length();i++) {
            count[s1[i] - 'a']++;
        }
        int loop = s2.length() - s1.length() + 1;
        for(int i=0;i<loop;i++) {
            if (count[s2[i] - 'a'] > 0) {
                if (isPermutation(count, s2.substr(i, s1.length()))) {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};