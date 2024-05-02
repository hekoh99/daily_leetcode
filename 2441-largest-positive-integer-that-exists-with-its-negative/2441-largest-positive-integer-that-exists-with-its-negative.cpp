class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        vector<int> isHere(1001, 0);
        for(int i=0;i<nums.size();i++) {
            if (nums[i] < 0) {
                if (isHere[nums[i] * -1] == 2) {
                    if (ans < (nums[i] *  -1))
                        ans = nums[i] * -1;
                }
                isHere[nums[i] * -1] = 1;
            }
            else {
                if (isHere[nums[i]] == 1) {
                    if (ans < (nums[i]))
                        ans = nums[i];
                }
                isHere[nums[i]] = 2;
            }
        }
        return ans;
    }
};