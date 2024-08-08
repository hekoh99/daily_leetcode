class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int winSize = 0;
        int tmp = 0;
        vector<int> cumulSum(n, 0);
        for(int i=0;i<n;i++) {
            if (nums[i] == 1) {
                winSize++;
            }
            cumulSum[i] = winSize;
        }
        if (winSize == 0)
            return 0;

        for(int i=0;i<winSize;i++) {
            cumulSum.push_back(cumulSum[i] + cumulSum[n - 1]);
        }

        ans = winSize - (cumulSum[winSize - 1]);
        for(int i=winSize;i<n + winSize;i++) {
            tmp = winSize - (cumulSum[i] - cumulSum[i - winSize]);
            if (ans > tmp)
                ans = tmp;
        }
        return ans;
    }
};