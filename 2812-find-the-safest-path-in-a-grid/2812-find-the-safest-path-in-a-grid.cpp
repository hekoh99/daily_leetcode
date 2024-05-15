class Solution {
private:
    bool findPath(vector<vector<int>>& grid, int min) {
        int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        int nextX, nextY;
        int n = grid.size();
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> cells;
        cells.push(make_pair(0, 0));
        while (!cells.empty()) {
            int size = cells.size();
            while(size > 0) {
                for(int i=0;i<4;i++) {
                    nextX = cells.front().first + dir[i][0];
                    nextY = cells.front().second + dir[i][1];
                    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                        if (visited[nextY][nextX] == 0 && grid[nextY][nextX] >= min) {
                            if (nextX == n - 1 && nextY == n - 1)
                                return true;
                            cells.push(make_pair(nextX, nextY));
                            visited[nextY][nextX] = 1;
                        }
                    }
                }
                cells.pop();
                size--;
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> thiefPos;
        
        int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    thiefPos.push(make_pair(j, i));
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = -1;
                }
            }
        }

        int nextX, nextY;
        while (!thiefPos.empty()) {
            int size = thiefPos.size();
            while (size > 0) {
                for(int i=0;i<4;i++) {
                    nextX = thiefPos.front().first + dir[i][0];
                    nextY = thiefPos.front().second + dir[i][1];
                    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                        if (grid[nextY][nextX] == -1) {
                            grid[nextY][nextX] = grid[thiefPos.front().second][thiefPos.front().first] + 1;
                            thiefPos.push(make_pair(nextX, nextY));
                        }
                    }
                }
                thiefPos.pop();
                size--;
            }
        }
        
        int ans = 0;
        int start = 0;
        int end = grid[0][0];
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (findPath(grid, mid)) {
                start = mid + 1;
                ans = mid;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};