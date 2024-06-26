class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int ans = 0;
        int n = nums.size();
        int min, max;
        int frontIdx = 0;
        
        for(int i=0;i<n;i++) {
            ms.insert(nums[i]);
            min  = *(ms.begin());
            max  = *(ms.rbegin());
            while (max - min > limit) {
                ms.erase(ms.find(nums[frontIdx]));
                frontIdx++;

                min  = *(ms.begin());
                max  = *(ms.rbegin());
            }
            if (ans < ms.size()) {
                ans = ms.size();
            }
        }
        return ans;
    }
};