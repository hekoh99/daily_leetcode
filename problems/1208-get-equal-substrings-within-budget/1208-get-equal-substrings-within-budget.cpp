class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        int end = 0;
        int cost = 0;
        int startIdx = 0;
        int len = 0;
        int max = 0;
        for(int i=0;i<s.size();i++) {
            diff.push_back(abs(s[i] - t[i]));
        }
        for (int i=0;i<diff.size();i++) {
            if (cost + diff[i] <= maxCost) {
                cost += diff[i];
                end = i;
            }
            else {
                int sum = 0;
                int j = 0;
                for(j=startIdx;j<=i;j++) {
                    sum += diff[j];
                    if (cost - sum + diff[i] <= maxCost) {
                        cost = cost - sum + diff[i];
                        end = i;
                        startIdx = j + 1;
                        break;
                    }
                }
                if (j == i && diff[j] > maxCost) {
                    cost = 0;
                    startIdx = j + 1;
                }
            }
            len = end - startIdx + 1;
            if (max < len)
                max = len;
        }
        return max;
    }
};