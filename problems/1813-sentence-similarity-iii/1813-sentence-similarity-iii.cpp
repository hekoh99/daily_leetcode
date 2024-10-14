class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> s1words, s2words;
        while (ss1 >> word) {
            s1words.push_back(word);
        }
        while (ss2 >> word) {
            s2words.push_back(word);
        }

        int start = 0;
        int s1count = s1words.size();
        int s2count = s2words.size();

        if (s1count > s2count) {
            return areSentencesSimilar(s2, s1);
        }

        for(int i=0;i<s1count;i++) {
            if (s1words[i] != s2words[i]) {
                break;
            }
            start++;
        }

        int end1 = s1count - 1, end2 = s2count - 1;
        while (end1 >= 0 && s1words[end1] == s2words[end2]) {
            end1--;
            end2--;
        }
        return end1 < start;
    }
};