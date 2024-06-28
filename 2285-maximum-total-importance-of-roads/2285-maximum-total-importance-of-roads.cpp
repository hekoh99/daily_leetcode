class Solution {
private:
    static bool compare(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> count(n, make_pair(-1, -1));
        for(int i=0;i<roads.size();i++) {
            for(int j=0;j<roads[i].size();j++) {
                count[roads[i][j]].first = roads[i][j];
                count[roads[i][j]].second++;
            }
        }
        sort(count.begin(), count.end(), compare);
        vector<int> value(n, 0);
        int importance = n;
        for(int i=0;i<count.size();i++) {
            if (count[i].first != -1) {            
                value[count[i].first] = importance;
                importance--;
            }
        }
        long long ans = 0;
        for(int i=0;i<roads.size();i++) {
            for(int j=0;j<roads[i].size();j++) {
                ans += (value[roads[i][j]]);
            }
        }
        return ans;
    }
};