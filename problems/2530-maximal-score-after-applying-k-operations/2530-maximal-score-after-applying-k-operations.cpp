class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
        }
        int tmp = 0;
        for(int i=0;i<k;i++) {
            ans += pq.top();
            tmp = ceil(double((double)pq.top() / 3));
            pq.pop();
            pq.push(tmp);
        }
        return ans;
    }
};