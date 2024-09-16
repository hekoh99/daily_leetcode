class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        int prev, cur;
        for(int i=1;i<timePoints.size();i++) {
            prev = stoi(timePoints[i-1].substr(0, 2)) * 60 + stoi(timePoints[i-1].substr(3, 2));
            cur = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
            if (ans > (cur - prev)%(24 * 60)) {
                ans = (cur - prev)%(24 * 60);
            }
        }
        prev = stoi(timePoints[0].substr(0, 2)) * 60 + stoi(timePoints[0].substr(3, 2));
        cur = 24 * 60 - cur;
        if (ans > prev + cur) {
            ans = prev + cur;
        }
        return ans;
    }
};