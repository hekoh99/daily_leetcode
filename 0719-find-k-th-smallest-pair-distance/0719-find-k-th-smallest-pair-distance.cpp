class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int ans = 0;
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> distanceBucket(maxElement + 1, 0);

        for(int i=0;i<nums.size() - 1;i++) {
            for(int j=i + 1;j<nums.size();j++) {
                distanceBucket[abs(nums[i] - nums[j])]++;
            }
        }
        for(int i=0;i<distanceBucket.size();i++) {
            k -= distanceBucket[i];
            if (k <= 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};