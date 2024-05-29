class Solution {
    string addOneToString(string s) {
        string result;
        for(int i=s.size() - 1;i>=0;i--) {
            if (s[i] == '1') {
                s[i] = '0';
            }
            else {
                s[i] = '1';
                break;
            }
        }
        if (s[0] == '0') {
            result.append("1");
            result.append(s);
        }
        else {
            result.append(s);
        }
        return result;
    }
public:
    int numSteps(string s) {
        int count = 0;
        while (strcmp(s.c_str(), "1") != 0) {
            if (s[s.size() - 1] == '0') {
                s = s.substr(0, s.size() - 1);
                count++;
            }
            else {
                s = addOneToString(s.substr(0, s.size() - 1));
                count += 2;
            }
        }
        return count;
    }
};