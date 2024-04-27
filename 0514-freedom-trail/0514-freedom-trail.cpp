class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int curIndex = 0;
        vector<int> distance;
        vector<int> indexOfAlpha[26];
        int dp[101][101] = {0, };
        int total = 0;
        for(int i=0;i<ring.size();i++) {
            indexOfAlpha[ring[i] - 'a'].push_back(i);
            if (i <= n / 2) {
                distance.push_back(i);
            }
            else
                distance.push_back(n - i);
        }
        int min = -1;
        for(int i=0;i<indexOfAlpha[key[0] - 'a'].size();i++) {
            dp[0][indexOfAlpha[key[0] - 'a'][i]] = distance[indexOfAlpha[key[0] - 'a'][i]] + 1;
            if (min == -1 || dp[0][indexOfAlpha[key[0] - 'a'][i]] < min)
                min = dp[0][indexOfAlpha[key[0] - 'a'][i]];
        }
        
        for(int i=1;i<key.size();i++) {
            min = -1;
            for(int j=0;j<indexOfAlpha[key[i] - 'a'].size();j++) {
                for(int k=0;k<indexOfAlpha[key[i-1] - 'a'].size();k++) {
                    int tmp = dp[i-1][indexOfAlpha[key[i-1] - 'a'][k]] + distance[(indexOfAlpha[key[i]-'a'][j] + n - indexOfAlpha[key[i-1] - 'a'][k]) % n] + 1;
                    if (dp[i][indexOfAlpha[key[i] - 'a'][j]] == 0 || dp[i][indexOfAlpha[key[i] - 'a'][j]] > tmp) {
                        dp[i][indexOfAlpha[key[i] - 'a'][j]] = tmp;
                    }
                }
                if (min == -1 || dp[i][indexOfAlpha[key[i] - 'a'][j]] < min) {
                    min = dp[i][indexOfAlpha[key[i] - 'a'][j]];
                }
            }
        }
        return min;
    }
};