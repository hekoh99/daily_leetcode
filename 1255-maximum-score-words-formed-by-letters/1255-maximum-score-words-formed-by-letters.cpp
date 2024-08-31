class Solution {
private:
    int findMaxScore(vector<string>& words, vector<int> counts, vector<int>& score, int index, int total) {
        if (words.size() == index){
            return total;
        }
        int curScore = 0;
        bool flag = false;
        vector<int> curCounts(26, 0);
        for(int i=0;i<words[index].length();i++) {
            curCounts[words[index][i] - 'a']++;
            curScore += score[words[index][i] - 'a'];
            if (counts[words[index][i] - 'a'] < curCounts[words[index][i] - 'a']) {
                flag = true;
                break;
            }
        }
        if (flag) {
            return findMaxScore(words, counts, score, index + 1, total);
        }

        int excluded = findMaxScore(words, counts, score, index + 1, total);
        for(int i=0;i<26;i++) {
            counts[i] -= curCounts[i];
        }
        int included = findMaxScore(words, counts, score, index + 1, total + curScore);
        int res = max(excluded, included);
        return res;
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> counts(26, 0);
        int ans = 0;
        for(int i=0;i<letters.size();i++) {
            counts[letters[i] - 'a']++;
        }
        ans = findMaxScore(words, counts, score, 0, 0);
        return ans;
    }
};