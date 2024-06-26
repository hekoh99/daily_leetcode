class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> accumSum;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i] % 2;
            if (sum == k) {
                ans++;
            }
            map<int, int>::iterator it = accumSum.find(sum - k);
            if (it != accumSum.end()) {
                ans += it->second;
            }
            it = accumSum.find(sum);
            if (it !=  accumSum.end()) {
                it->second++;
            }
            else {
                accumSum.insert(make_pair(sum, 1));
            }
        }
        return ans;
    }
};