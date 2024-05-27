class Solution {
public:
    int specialArray(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            if (nums[i] >= nums.size() - i) {
                if (i == 0 || nums[i - 1] < nums.size() - i)
                    return nums.size() - i;
            }
        }
        return -1;
    }
};