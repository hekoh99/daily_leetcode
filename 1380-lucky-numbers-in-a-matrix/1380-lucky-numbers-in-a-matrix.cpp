class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> colMax(n, 0);
        vector<int> rowMin(m, 1000000);
        vector<int> ans;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (colMax[j] < matrix[i][j]) {
                    colMax[j] = matrix[i][j];
                }
                if (rowMin[i] > matrix[i][j]) {
                    rowMin[i] = matrix[i][j];
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (rowMin[i] == colMax[j]) {
                    ans.push_back(rowMin[i]);
                }
            }
        }
        return ans;
    }
};