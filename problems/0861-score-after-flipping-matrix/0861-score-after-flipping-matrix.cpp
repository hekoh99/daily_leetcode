class Solution {
private:
    void toggle(vector<vector<int>>& grid, int target, int isRow) {
        int zeros = 0;
        if (isRow) {
            for(int i=0;i<grid[0].size();i++) {
                grid[target][i] = grid[target][i] == 0 ? 1 : 0;
            }
        }
        else {
            for(int i=0;i<grid.size();i++) {
                if (grid[i][target] == 0) {
                    zeros++;
                }
            }
            if (zeros > grid.size() / 2) {
                for(int i=0;i<grid.size();i++) {
                    grid[i][target] = grid[i][target] == 0 ? 1 : 0;
                }
            }
        }
    }

    int binarySum(vector<vector<int>>& grid) {
        int sum = 0;
        int num = 0;
        for(int i=0;i<grid.size();i++) {
            num = 0;
            for(int j=0;j<grid[0].size();j++) {
                num = num * 2;
                num +=  grid[i][j];
            }
            sum += num;
        }
        return sum;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 0) {
                    if (j == 0) {
                        toggle(grid, i, true);
                    }
                    else {
                        toggle(grid, j, false);
                    }
                }
            }
        }
        return binarySum(grid);
    }
};