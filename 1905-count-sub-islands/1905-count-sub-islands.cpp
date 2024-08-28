class Solution {
private:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

private:
    bool findIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int x, int y) {
        bool res = true;

        if (grid1[y][x] == 0 && grid2[y][x] == 1) {
            res = false;
        }

        int nextY, nextX, tmp;
        for(int i=0;i<4;i++) {
            nextX = x + dir[i][0];
            nextY = y + dir[i][1];
            if (nextX >= 0 && nextX < grid1[0].size()) {
                if (nextY >= 0 && nextY < grid1.size()) {
                    if (grid2[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
                        visited[nextY][nextX] = true;
                        tmp = findIsland(grid1, grid2, visited, nextX, nextY);
                        res = (res && tmp);
                        // visited[nextY][nextX] = false;
                    }
                }
            }
        }
        return res;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> visited(500, vector<bool>(500, false));
        int ans = 0;
        for(int i=0;i<grid1.size();i++) {
            for(int j=0;j<grid1[0].size();j++) {
                if (grid2[i][j] == 1 && visited[i][j] == false) {
                    visited[i][j] = true;
                    if (findIsland (grid1, grid2, visited, j, i)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};