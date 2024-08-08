class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = true;
        int jump = nums[0];
        for(int i=1;i<nums.size();i++) {
            if (jump == 0) {
                ans = false;
                break;
            }
            jump = jump - 1 > nums[i] ? jump - 1 : nums[i];
        }
        return ans;
    }
};