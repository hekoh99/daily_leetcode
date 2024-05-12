class Solution {
private:
    int findLocalMax(vector<vector<int>>& grid, int x, int y) {
        int localMax = 0;
        for(int i=y;i<y + 3;i++) {
            for(int j=x;j<x + 3;j++) {
                localMax = localMax < grid[i][j] ? grid[i][j] : localMax;
            }
        }
        return localMax;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> localMax(n - 2);
        for(int i=0;i<n - 2;i++) {
            for(int j=0;j<n - 2;j++) {
                localMax[i].push_back(findLocalMax(grid, j, i));
            }
        }
        return localMax;
    }
};