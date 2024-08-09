class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        vector<int> jumps;
        jumps.push_back(0);
        jumps.push_back(nums[0]);
        int curJump = 1;
        for(int i=1;i<nums.size();i++) {
            if (i > jumps[curJump]) {
                curJump++;
            }
            for(int j=curJump + 1;j<jumps.size();j++) {
                if (jumps[j - 1] >= i) {
                    if (jumps[j] < i + nums[i]) {
                        jumps[j] = i + nums[i];
                    }
                }
            }
            jumps.push_back(i + nums[i]);
        }
        return curJump;
    }
};
