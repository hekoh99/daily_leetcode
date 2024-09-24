class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp;
        for(int i=0;i<matrix.size()/2;i++) {
            for(int j=0;j<matrix.size();j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - i  - 1][j];
                matrix[matrix.size() - i  - 1][j] = tmp;
            }
        }
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<i;j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};