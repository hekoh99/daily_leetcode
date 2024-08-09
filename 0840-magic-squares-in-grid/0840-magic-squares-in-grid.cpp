class Solution {
private:
    bool isMagicSquareCore(vector<vector<int>>& grid, int x, int y) {
        bool res = true;
        int rowSum = 0;
        vector<int> colSum(3, 0);
        vector<int> count(10, 0);

        for(int i=y-1;i<=y+1;i++) {
            rowSum = 0;
            for(int j=x-1;j<=x+1;j++) {
                if (grid[i][j] > 9 || grid[i][j] < 1) {
                    return false;
                }
                if (count[grid[i][j]] > 0) {
                    return false;
                }
                count[grid[i][j]]++;
                rowSum += grid[i][j];
                colSum[j - (x - 1)] += grid[i][j];
            }
            if (rowSum != 15) {
                return false;
            }
        }
        if (colSum[0] != 15 || colSum[1] != 15 || colSum[2] != 15) {
            return false;
        }
        if (grid[y][x] + grid[y - 1][x - 1] + grid[y + 1][x + 1] != 15) {
            return false;
        }
        if (grid[y][x] + grid[y - 1][x + 1] + grid[y + 1][x - 1] != 15) {
            return false;
        }
        return res;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int w = grid[0].size();
        int h = grid.size();
        int ans = 0;

        if (w < 3 || h < 3)
            return 0;
        
        for(int i=1;i<h-1;i++) {
            for(int j=1;j<w-1;j++) {
                if (isMagicSquareCore(grid, j, i)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};