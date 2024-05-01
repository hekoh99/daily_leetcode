class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find(ch);
        if (pos == string::npos) {
            return word;
        }
        string ans(word.rbegin() + word.length() - pos - 1, word.rend());
        ans.append(word.substr(pos + 1));
        return ans;
    }
};