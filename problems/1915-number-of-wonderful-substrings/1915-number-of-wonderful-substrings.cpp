class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        map<int, int> freqMap;

        freqMap.insert(make_pair(0, 1));
        int mask = 0;
        for(int i=0;i<word.length();i++) {
            int bit = word[i] - 'a';
            mask ^= (1 << bit);
            
            map<int, int>::iterator freq;
            freq = freqMap.find(mask);
            if (freq != freqMap.end()) {
                ans += (*freq).second;
                (*freq).second += 1;
            } else {
                freqMap.insert(make_pair(mask, 1));
            }
            for(int j=0;j<10;j++) {     // a ~ j
                map<int, int>::iterator freq_diff1 = freqMap.find(mask ^ (1 << j));
                if (freq_diff1 != freqMap.end()) {
                    ans += (*freq_diff1).second;
                }
            }
        }
        return ans;
    }
};