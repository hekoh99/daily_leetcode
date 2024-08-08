class Solution {
private:
    vector<vector<int>> dir;
private:
    void init() {
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({-1, 0});
        dir.push_back({0, -1});
    }

    bool isValid(int rowMax, int colMax, pair<int, int>& pos) {
        int x = pos.first;
        int y = pos.second;
        if (x < 0 || y < 0 || x >= colMax || y >= rowMax)
            return false;
        return true;
    }

    pair<int, int> nextCoordinate(pair<int, int>& curPos, int dirIndex) {
        pair<int, int> nextPos;
        nextPos.first = curPos.first + dir[dirIndex][0];
        nextPos.second = curPos.second + dir[dirIndex][1];
        return nextPos;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int total = rows * cols;
        pair<int, int> curPos = {cStart, rStart};
        int targetLen = 2;
        int curLen = 0;     // targetLen 까지 증가
        int cycle = 0;      // 2까지 증가. (변의 길이가 같은 건 2개);
        int dirIndex = 0;

        init();
        while (total > 0) {
            if (isValid(rows, cols, curPos)) {
                ans.push_back({curPos.second, curPos.first});
                total--;
            }
            curLen++;
            if (curLen == targetLen) {
                curLen = 1;
                dirIndex = (dirIndex + 1) % 4;
                cycle++;
                if (cycle == 2) {
                    cycle = 0;
                    targetLen++;
                }
            }
            curPos.first = curPos.first + dir[dirIndex][0];
            curPos.second = curPos.second + dir[dirIndex][1];
        }

        return ans;
    }
};