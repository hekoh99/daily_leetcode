class Solution {
private:
    int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
    int max;
private:
    void doMining(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int gold) {
        int n = grid.size();
        int m = grid[0].size();
        int nxtX, nxtY;
        visited[y][x] = 1;
        gold += grid[y][x];
        for(int i=0;i<4;i++) {
            nxtX = x + dir[i][0];
            nxtY = y + dir[i][1];
            if (nxtX >= 0 && nxtX < m && nxtY >= 0 && nxtY < n) {
                if (visited[nxtY][nxtX] != 1 && grid[nxtY][nxtX] != 0) {
                    doMining(grid, visited, nxtX, nxtY, gold);
                    visited[nxtY][nxtX] = 0;
                }
            }
        }
        if (max < gold) {
            max = gold;
        }
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        max = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (grid[i][j] != 0) {
                    doMining(grid, visited, j, i, 0);
                    visited[i][j] = 0;
                }
            }
        }
        return max;
    }
};