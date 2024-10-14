class Solution {
private:
    bool validCoordinate(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n) {
            return true;
        }
        return false;
    }

    int countLiveNeighbors(vector<vector<int>>& board, int x, int y) {
        int count = 0;
        vector<vector<int>> dir = {{1, 0},{-1, 0},{0, 1},{0, -1},{1, 1},{1, -1},{-1, -1},{-1, 1}};
        int nextX, nextY, m = board[0].size(), n = board.size();

        for(int i=0;i<dir.size();i++) {
            nextX = x + dir[i][0];
            nextY = y + dir[i][1];

            if (validCoordinate(nextX, nextY, m, n)) {
                if (board[nextY][nextX] == 1)
                    count++;
            }
        }
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbor = 0;
        vector<pair<int, int>> change;

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                neighbor = countLiveNeighbors(board, j, i);
                if (board[i][j] == 1) {
                    if (neighbor < 2 || neighbor > 3) {
                        change.push_back(make_pair(j, i));
                    }
                }
                else {
                    if (neighbor == 3) {
                        change.push_back(make_pair(j, i));
                    }
                }
            }
        }

        pair<int, int> target;
        for(int i=0;i<change.size();i++) {
            target = change[i];
            board[target.second][target.first] ^= 1;
        }
    }
};