class Solution {
public:
    int minFallingPathSum(vector<vector<int> >& grid) {
        vector<vector<int> > dp(grid);
        int n = grid.size();
        int prevCol = 0;
        int curMin = 200000;
        int curSecMin = 200000;
        int curMinCol = -1;

        int prevMin = 200000;
        int prevSecMin = 200000;

        if (n == 1)
            return grid[0][0];
        for(int i=0;i<n;i++) {
            if (prevMin > grid[0][i]) {
                prevCol = i;
                prevSecMin = prevMin;
                prevMin = grid[0][i];
            }
            if (prevCol != i && grid[0][i] >= prevMin && grid[0][i] < prevSecMin) {
                prevSecMin = grid[0][i];
            }
        }
        for(int i=1;i<n;i++) {
            curMin = 200000;
            curSecMin = 200000;
            curMinCol = -1;
            for(int j=0;j<n;j++) {
                if (j == prevCol) {
                    dp[i][j] += prevSecMin;
                } else {
                    dp[i][j] += prevMin;
                }

                if (curMin > dp[i][j]) {
                    curMinCol = j;
                    curSecMin = curMin;
                    curMin = dp[i][j];
                }
                if (curMinCol != j && dp[i][j] >= curMin && dp[i][j] < curSecMin) {
                    curSecMin = dp[i][j];
                }
            }
            prevCol = curMinCol;
            prevSecMin = curSecMin;
            prevMin = curMin;
        }
        return curMin;
    }
};