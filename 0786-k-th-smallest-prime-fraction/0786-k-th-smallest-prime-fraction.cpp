class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if (arr.size() == 2) {
            return arr;
        }
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(int i=0;i<arr.size() - 1;i++) {
            for(int j=i+1;j<arr.size();j++) {
                pq.push(make_pair((double)arr[i]/arr[j], make_pair(arr[i], arr[j])));
            }
        }
        int index = 0;
        while (!pq.empty()) {
            if (index >= k - 1) {
                break;
            }
            pq.pop();
            index++;
        }
        vector<int> ans = {pq.top().second.first, pq.top().second.second};
        return ans;
    }
};