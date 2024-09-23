class Solution {
private:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // x, y
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dirIndex = 0;
        int x = 0, y = 0;
        bool flag = false;
        int count = 0;
        vector<int> ans;
        while (count < matrix.size() * matrix[0].size()) {
            ans.push_back(matrix[y][x]);
            matrix[y][x] = 1000; // visited
            flag = false;
            if (x + dir[dirIndex][0] >= 0 && x + dir[dirIndex][0] < matrix[0].size()) {
                if (y + dir[dirIndex][1] >= 0 && y + dir[dirIndex][1] < matrix.size()) {
                    if (matrix[y + dir[dirIndex][1]][x + dir[dirIndex][0]] != 1000) {
                        flag = true;
                    }
                }
            }
            if (flag == false) {
                dirIndex = (dirIndex + 1) % 4;
            }
            x += dir[dirIndex][0];
            y += dir[dirIndex][1];
            count++;
        }
        return ans;
    }
};