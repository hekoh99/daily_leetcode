class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<score.size();i++) {
            pq.push(make_pair(score[i], i));
        }
        int index = 0;
        while (!pq.empty()) {
            switch(index) {
                case 0:
                    ans[pq.top().second] = "Gold Medal";
                    break;
                case 1:
                    ans[pq.top().second] = "Silver Medal";
                    break;
                case 2:
                    ans[pq.top().second] = "Bronze Medal";
                    break;
                default:
                    ans[pq.top().second].append(to_string(index + 1));
                    break;
            }
            index++;
            pq.pop();
        }
        return ans;
    }
};