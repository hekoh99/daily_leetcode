class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>> &edges) {
        vector<int> didXor;
        long long total = 0;
        int leastDiff = 2147483647;
        for(int i=0;i<nums.size();i++) {
            if ((nums[i] ^ k) > nums[i]) {
                nums[i] = nums[i] ^ k;
                didXor.push_back(i);
            }
            else {
                int diff = nums[i] - (nums[i] ^ k);
                if (leastDiff > diff)
                    leastDiff = diff;
            }
            total += nums[i];
            
        }
        if (didXor.size() % 2 == 0) {
            return total;
        }

        int max = 0;
        int tmp = 0;
        for(int i=0;i<didXor.size();i++) {
            tmp = total - nums[didXor[i]] + (nums[didXor[i]] ^ k) > total - leastDiff ? total - nums[didXor[i]] + (nums[didXor[i]] ^ k) : total - leastDiff;
            if (max < tmp) {
                max = tmp;
            }
        }
        return max;
    }
};