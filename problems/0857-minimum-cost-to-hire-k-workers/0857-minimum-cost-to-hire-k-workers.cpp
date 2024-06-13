class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double ans = -1;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        priority_queue<int> groupPq;
        for(int i=0;i<n;i++) {
            pq.push(make_pair((double) wage[i]/quality[i], quality[i]));
        }
        int total = 0;
        double groupWage = 0;
        double wageProportion = 0;
        while (!pq.empty()) {
            if (groupPq.size() < k) {
                total += pq.top().second;
                wageProportion = pq.top().first;
                groupPq.push(pq.top().second);
                pq.pop();
            }
            else {
                groupWage = total * wageProportion;
                if (ans < 0 || ans > groupWage) {
                    ans = groupWage;
                }
                total -= groupPq.top();
                groupPq.pop();
            }
        }
        if (groupPq.size() == k) {
            groupWage = total * wageProportion;
            if (ans < 0 || ans > groupWage) {
                ans = groupWage;
            }
        }
        return ans;
    }
};