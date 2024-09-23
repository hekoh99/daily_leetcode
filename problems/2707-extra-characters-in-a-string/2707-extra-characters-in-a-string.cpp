class Solution {
private:
    int ans;
private:
    void findMin(string& s, size_t pos, vector<string>& dict, int extraCount) {
        if (extraCount >= ans)
            return ;
        
        if (pos >= s.length()) {
            if (extraCount < ans)
                ans = extraCount;
            return;
        }
        size_t foundPos;
        for(int i=0;i<dict.size();i++) {
            foundPos = s.find(dict[i], pos);
            if (foundPos != string::npos) {
                findMin(s, foundPos + dict[i].length(), dict, extraCount + (foundPos - pos));
            }
            else {
                findMin(s, s.length(), dict, extraCount + (s.length() - pos));
            }
        }
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        ans = s.length();
        size_t pos;

        for(int i=0;i<dictionary.size();i++) {
            pos = s.find(dictionary[i]);
            if (pos != string::npos) {
                findMin(s, pos + dictionary[i].length(), dictionary, pos);
            }
        }
        return ans;
    }
};