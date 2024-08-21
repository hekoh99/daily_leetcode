class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int leftVal = 1;
        int rightVal = 1;

        for(int i=0;i<nums.size();i++) {
            left[i] = leftVal;
            leftVal *= nums[i];

            right[nums.size() - i - 1] = rightVal;
            rightVal *= nums[nums.size() - i - 1];
        }

        for(int i=0;i<nums.size();i++) {
            ans.push_back(left[i] * right[i]);
        }
        return ans;
    }
};