class Solution {
private:
    int defineBox(int x, int y) {
        if (x < 3) {
            if (y < 3) 
                return 0;
            if (y < 6)
                return 3;
            if (y < 9)
                return 6;
        }
        if (x < 6) {
            if (y < 3) 
                return 1;
            if (y < 6)
                return 4;
            if (y < 9)
                return 7;
        }
        if (x < 9) {
            if (y < 3) 
                return 2;
            if (y < 6)
                return 5;
            if (y < 9)
                return 8;
        }
        return -1;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(10);
        vector<set<int>> cols(10);
        vector<set<int>> boxes(10);
        int box;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rows[i].find(board[i][j]) != rows[i].end()) {
                    return false;
                }
                if (cols[j].find(board[i][j]) != cols[j].end()) {
                    return false;
                }
                box = defineBox(j, i);
                if (boxes[box].find(board[i][j]) != boxes[box].end()) {
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[box].insert(board[i][j]);
            }
        }
        return true;
    }
};
