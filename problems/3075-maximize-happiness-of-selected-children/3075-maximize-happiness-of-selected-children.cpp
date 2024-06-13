class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(happiness.begin(), happiness.end());
        long long ans = 0;
        int decrement = 0;
        for(int i=0;i<k;i++) {
            if (pq.top() - decrement >= 0) {
                ans += (pq.top() - decrement);
            }
            pq.pop();
            decrement++;
        }
        return ans;
    }
};