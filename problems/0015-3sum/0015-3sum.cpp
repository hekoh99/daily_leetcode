class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int j, k, prev;

        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == (nums[i] * -1)) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    prev = nums[j];
                    while (j < nums.size() && prev == nums[j])
                        j++;
                    prev = nums[k];
                    while (k > 0 && prev == nums[k])
                        k--;
                }
                else if (nums[j] + nums[k] > (nums[i] * -1)) {
                    prev = nums[k];
                    while (k > 0 && prev == nums[k])
                        k--;
                }
                else if (nums[j] + nums[k] < (nums[i] * -1)) {
                    prev = nums[j];
                    while (j < nums.size() && prev == nums[j])
                        j++;
                }
            }
        }
        return ans;
    }
};