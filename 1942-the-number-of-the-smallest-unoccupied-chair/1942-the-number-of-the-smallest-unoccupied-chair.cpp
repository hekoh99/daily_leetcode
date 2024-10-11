class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int ans = 0;
        int n = times.size();
        vector<pair<pair<int, int>, int>> info;
        for(int i=0;i<times.size();i++) {
            info.push_back(make_pair(make_pair(times[i][0], times[i][1]), i));
        }

        sort(info.begin(), info.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        priority_queue<int, vector<int>, greater<int>> seat;
        pair<int, int> next;
        int nextSeat;
        seat.push(0);
        for(int i=0;i<info.size();i++) {
            next = info[i].first;
            nextSeat = pq.size();
            while (!pq.empty() && pq.top().first <= next.first) {
                seat.push(pq.top().second);
                pq.pop();
            }
            if (!seat.empty() && seat.top() <= nextSeat) {
                nextSeat = seat.top();
                seat.pop();
            }
            if (info[i].second == targetFriend) {
                ans = nextSeat;
                break;
            }
            pq.push({next.second, nextSeat});
        }

        return ans;   
    }
};