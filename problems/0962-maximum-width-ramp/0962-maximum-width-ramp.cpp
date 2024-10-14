class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        vector<pair<int, int>> sorted;
        for(int i=0;i<nums.size();i++) {
            sorted.push_back(make_pair(nums[i], i));
        }
        sort(sorted.begin(), sorted.end());
        int minIndex = nums.size();
        for(int i=0;i<sorted.size();i++) {
            ans = max(ans, sorted[i].second - minIndex);
            minIndex = min(sorted[i].second, minIndex);
        }

        return ans;
    }
};