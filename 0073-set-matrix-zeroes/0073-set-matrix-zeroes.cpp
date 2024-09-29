class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        set<int>::iterator it;
        int index = 0;
        for(it = rows.begin();it != rows.end();it++) {
            index = *it;
            for(int i=0;i<matrix[index].size();i++) {
                matrix[index][i] = 0;
            }
        }
        for(it = cols.begin();it != cols.end();it++) {
            index = *it;
            for(int i=0;i<matrix.size();i++) {
                matrix[i][index] = 0;
            }
        }
    }
};