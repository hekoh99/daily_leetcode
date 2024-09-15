class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int len = 0;
        int curMax = 0;
        int prev = 0;
        for(int i=0;i<nums.size();i++) {
            if (nums[i] != prev) {
                if (len > ans) {
                    ans = len;
                }
                len = 0;
                if (nums[i] > curMax) {
                    curMax = nums[i];
                    ans = 0;
                }
            }

            if (nums[i] == curMax) {
                len++;
            }
            prev = nums[i];
        }
        if (len > ans)
            ans = len;
        return ans;
    }
};