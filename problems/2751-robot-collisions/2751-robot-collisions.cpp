class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        int n = positions.size();
        // pos, index
        vector<pair<int, int>> line;
        for(int i=0;i<n;i++) {
            line.push_back(make_pair(positions[i], i));
        }
        sort(line.begin(), line.end());
        
        vector<int> right;
        int collide;
        int curIndex;
        for(int i=0;i<n;i++) {
            curIndex = line[i].second;
            if (directions[curIndex] == 'R') {
                right.push_back(curIndex);
            }
            else {
                while (right.size() > 0) {
                    collide = right.back();

                    if (healths[collide] == healths[curIndex]) {
                        healths[collide] = 0;
                        healths[curIndex] = 0;
                        right.pop_back();
                        break;
                    }
                    else if (healths[collide] > healths[curIndex]) {
                        healths[collide] -= 1;
                        healths[curIndex] = 0;
                        break;
                    }
                    else {
                        healths[collide] = 0;
                        healths[curIndex] -= 1;
                        right.pop_back();
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};