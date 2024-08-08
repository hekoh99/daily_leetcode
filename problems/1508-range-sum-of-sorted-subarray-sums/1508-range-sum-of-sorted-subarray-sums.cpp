class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        int ans = 0;

        sums.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            sums.push_back(sums.back() + nums[i]);
        }
        for(int i=1;i<nums.size();i++) {
            for(int j=i-1;j >= 0;j--) {
                sums.push_back(sums[i] - sums[j]);
            }
        }
        sort(sums.begin(), sums.end());
        for(int i=left-1;i<right;i++) {
            ans += sums[i];
            ans = ans % (1000000000 + 7);
        }
        return ans;
    }
};