class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 4)
            return 0;
        int size = nums.size() - 4;
        
        // sum[i] = nums[i + 1] - nums[0]
        // find min of sum[i + size] - sum[i]
        int ans = nums[size] - nums[0]; 
        for(int i=0;i<nums.size() - size;i++) {
            if (ans > nums[i + size] - nums[i])
                ans = nums[i + size] - nums[i];
        }
        return ans;
    }
};