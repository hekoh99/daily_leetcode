class Solution {
public:
    string reverseWords(string s) {
        deque<string> words;
        string ans;
        int start = 0, end;
        string tmp;

        while (s.length() > 0) {
            if (s[start] == ' ') {
                s.erase(start, 1);
                continue;
            }
            end = s.find(' ');
            words.push_front(s.substr(start, end));
            s.erase(start, end - start);
        }

        for(int i=0;i<words.size();i++) {
            if (words[i].size() > 0) {
                if (i != 0) {
                    ans.append(" ");
                }
                ans.append(words[i]);
            }
        }
        return ans;
    }
};