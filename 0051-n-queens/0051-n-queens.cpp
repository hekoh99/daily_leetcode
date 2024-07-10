class Solution {
private:
    void setQueens(std::deque<std::pair<int, int>>& queens, int n, vector<vector<string>> &ans) {
        int curRow = queens.size();
        if (queens.size() == n) {
            vector<string> board;
            char row[10] = {0, };
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if (j == queens[i].first)
                        row[j] = 'Q';
                    else
                        row[j] = '.';
                }
                board.push_back(string(row));
            }
            ans.push_back(board);
            return ;
        }
        
        int arr[10] = {0, };
        for(int i=0;i<queens.size();i++) {
            for(int j=0;j<n;j++) {
                if (j == queens[i].first) 
                    arr[j] = 1;
                else if (curRow == queens[i].second)
                    arr[j] = 1;
                else if (j - queens[i].first == curRow - queens[i].second)
                    arr[j] = 1;
                else if (j - queens[i].first == queens[i].second - curRow)
                    arr[j] = 1;
            }
        }
        for(int i=0;i<n;i++) {
            if (arr[i] != 1) {
                queens.push_back(make_pair(i, curRow));
                setQueens(queens, n, ans);
                queens.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        deque<pair<int, int>> queens;
        for(int i=0;i<n;i++) {
            queens.push_back(make_pair(i, 0));
            setQueens(queens, n, ans);
            queens.clear();
        }
        return ans;
    }
};