class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        multimap<int, int, greater<int>> mapper;
        int total = 0;
        for(int i=0;i<difficulty.size();i++) {
            mapper.insert(make_pair(profit[i], difficulty[i]));
        }
        multimap<int, int, greater<int>>::iterator it;
        for(int i=0;i<worker.size();i++) {
            for(it = mapper.begin();it != mapper.end();it++) {
                if (worker[i] >= (*it).second) {
                    total += (*it).first;
                    break;
                }
            }
        }
        return total;
    }
};