class Solution {
public:
    int appendCharacters(string s, string t) {
        int pos = 0;
        int consist = 0;
        int i, j;
        for(i=0;i<t.size();i++) {
            for(j=pos;j<s.size();j++) {
                if (s[j] == t[i])
                {
                    pos = j + 1;
                    break;
                }
            }
            if (j == s.size()) {
                consist = i;
                break;
            }
        }
        if (i == t.size()) {
            return 0;
        }
        return t.size() - consist;
    }
};