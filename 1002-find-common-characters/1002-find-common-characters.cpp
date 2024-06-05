class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        multiset<char> tmp;
        multiset<char> intersec(words[0].begin(), words[0].end());
        vector<string> ans;
        
        for(int i=1;i<words.size();i++) {
            for(int j=0;j<words[i].length();j++) {
                multiset<char>::iterator it = intersec.find(words[i][j]);
                if (it != intersec.end()) {
                    intersec.erase(it);
                    tmp.insert(words[i][j]);
                }
            }
            intersec.clear();
            intersec = tmp;
            tmp.clear();
        }
        multiset<char>::iterator it;
        for(it = intersec.begin();it != intersec.end();it++) {
            string charToString;
            charToString += (*it);
            ans.push_back(charToString);
            charToString.clear();
        }
        return ans;
    }
};