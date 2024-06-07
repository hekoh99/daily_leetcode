class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string delim = " ";
        vector<string> words;
        sort(dictionary.begin(), dictionary.end());
        size_t pos = 0;
        while ((pos = sentence.find(delim)) != string::npos) {
            words.push_back(sentence.substr(0, pos));
            sentence.erase(0, pos + delim.length());
        }
        words.push_back(sentence);
        string ans;
        
        for(int i=0;i<words.size();i++) {
            for(int j=0;j<dictionary.size();j++) {
                if (strncmp(dictionary[j].c_str(), words[i].c_str(), dictionary[j].length()) == 0) {
                    words[i].clear();
                    words[i].append(dictionary[j]);
                    break;
                }
            }
            if (ans.length() != 0) {
                ans.append(" ");
            }
            ans.append(words[i]);
        }
        return ans;
    }
};