class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        vector<int> tmp;
        int freq = 0;
        int prev = nums[0];
        for(int i=0;i<nums.size();i++) {
            if (prev != nums[i])
                freq = 0;
            if (freq < 2) {
                tmp.push_back(nums[i]);
                freq++;
                k++;
            }
            prev = nums[i];
        }
        nums.assign(tmp.begin(), tmp.end());
        return k;
    }
};