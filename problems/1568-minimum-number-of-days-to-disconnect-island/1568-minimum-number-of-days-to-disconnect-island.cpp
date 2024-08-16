class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

private:
    bool exploreIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[y][x] = true;
        int nextX, nextY;
        bool flag = false;

        for(int i=0;i<4;i++) {
            nextX = x + dir[i][0];
            nextY = y + dir[i][1];
            if (nextX >= 0 && nextX < grid[0].size()) {
                if (nextY >= 0 && nextY < grid.size()) {
                    if (grid[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
                        if (exploreIsland(grid, visited, nextX, nextY)) {
                            flag = true;
                        }
                    }
                }
            }
        }
        return flag;
    }

    int countIsland(vector<vector<int>>& grid) {
        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    exploreIsland(grid, visited, j, i);
                    count++;
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int count = countIsland(grid);

        if (count != 1)
            return 0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIsland(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};