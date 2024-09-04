class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
private:
    pair<int, int> getNextPos(vector<vector<int>>& obs, int x, int y, int heading, int cmd) {
        pair<int, int> res;
        res.first = x + (dir[heading][0] * cmd);
        res.second = y + (dir[heading][1] * cmd);
        for(int i=0;i<obs.size();i++) {
            switch (heading) {
                case 0:
                    if (obs[i][0] == x) {
                        if (obs[i][1] > y && obs[i][1] <= res.second) {
                            res.second = obs[i][1] - 1;
                        }
                    }
                    break;
                case 1:
                    if (obs[i][1] == y) {
                        if (obs[i][0] > x && obs[i][0] <= res.first) {
                            res.first = obs[i][0] - 1;
                        }
                    }
                    break;
                case 2:
                    if (obs[i][0] == x) {
                        if (obs[i][1] < y && obs[i][1] >= res.second) {
                            res.second = obs[i][1] + 1;
                        }
                    }
                    break;
                case 3:
                    if (obs[i][1] == y) {
                        if (obs[i][0] < x && obs[i][0] >= res.first) {
                            res.first = obs[i][0] + 1;
                        }
                    }
                    break;
            }
        }
        return res;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        int heading = 0;
        int x = 0, y = 0;
        for(int i=0;i<commands.size();i++) {
            switch(commands[i]) {
                case -2:
                    heading = (heading + 3) % 4;
                    break;
                case -1:
                    heading = (heading + 1) % 4;
                    break;
                default:
                    pair<int, int> next = getNextPos(obstacles, x, y, heading, commands[i]);
                    x = next.first;
                    y = next.second;
                    break;
            }
            if (x * x + y * y > ans) {
                ans = x * x + y * y;
            }
        }
        return ans;
    }
};