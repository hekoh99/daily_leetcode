class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0;

        vector<long long> prevRow(points[0].size(), 0);
        for (int i=0;i<points[0].size();i++) {
            prevRow[i] = points[0][i];
        }

        for(int i=1;i<points.size();i++) {
            vector<long long> curMax(points[0].size(), 0);
            vector<long long> leftMax(points[0].size(), 0);
            vector<long long> rightMax(points[0].size(), 0);

            leftMax[0] = prevRow[0];
            for(int j=1;j<points[i].size();j++) {
                leftMax[j] = max(leftMax[j - 1] - 1, prevRow[j]);
            }

            rightMax[points[i].size() - 1] = prevRow[points[i].size() - 1];
            for(int j=points[i].size() - 2;j>=0;j--) {
                rightMax[j] = max(rightMax[j + 1] - 1, prevRow[j]);
            }

            for(int j=0;j<points[i].size();j++) {
                curMax[j] = max(leftMax[j], rightMax[j]);
                curMax[j] += points[i][j];
            }
            prevRow = curMax;
        }
        for(int i=0;i<points[0].size();i++) {
            ans = max(ans, prevRow[i]);
        }
        return ans;
    }
};