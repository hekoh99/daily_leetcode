class Solution {
private:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
private:
    bool isValid(int x, int y, int m, int n, vector<vector<int>>& mat) {
        if (x >= 0 && x < n) {
            if (y >= 0 && y < m) {
                if (mat[y][x] == -1) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int dirIndex = 0;
        int x = 0, y = 0;
        int count = 0;
        ListNode *tmp = head;

        while (count < m * n) {
            while (isValid(x, y, m, n, ans)) {
                if (tmp == NULL)
                    break;
                ans[y][x] = tmp->val;
                x += dir[dirIndex][0];
                y += dir[dirIndex][1];
                tmp = tmp->next;
                count++;
            }
            if (tmp == NULL)
                break;
            x -= dir[dirIndex][0];
            y -= dir[dirIndex][1];
            dirIndex = (dirIndex + 1) % 4;
            x += dir[dirIndex][0];
            y += dir[dirIndex][1];
        }
        
        return ans;
    }
};