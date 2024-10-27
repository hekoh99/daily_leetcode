class Solution {
private:
    int countSubSets(vector<int>& nums, int index, int cur, int target) {
        if (index == nums.size()) {
            if (cur == target)
                return 1;
            else 
                return 0;
        }

        int countWithout = countSubSets(nums, index + 1, cur, target);

        int countWith = countSubSets(nums, index + 1, cur | nums[index], target);
        return countWithout + countWith;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(int i=0;i<nums.size();i++) {
            target |= nums[i];
        }
        return countSubSets(nums, 0, 0, target);
    }
};