class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> counts(100001, 0);
        int ans = 0;
        int tmp = 0;
        for(int i=0;i<nums.size();i++) {
            tmp = nums[i];
            while(counts[tmp] > 0 && tmp < 100000) {
                tmp++;
                ans++;
            }
            counts[tmp]++;
        }
        ans += ((counts[100000]) * (counts[100000] - 1)) / 2;
        return ans;
    }
};