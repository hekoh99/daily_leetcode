class Solution {
private:
    bool isFlipNeeded(int currentNum, int flippedHistory) {
        if (currentNum == 1 && flippedHistory % 2 == 1)
            return true;
        if (currentNum == 0 && flippedHistory % 2 == 0)
            return true;
        return false;
    }
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> flipped(nums.size(), false);
        int ans = 0;
        int flippedCountInWindow = 0;

        for(int i=0;i<nums.size();i++) {
            if (i >= k) {
                if (flipped[i - k])
                    flippedCountInWindow--;
            }

            if (isFlipNeeded(nums[i], flippedCountInWindow)) {
                if (i + k > nums.size())
                    return -1;
                flipped[i] = true;
                flippedCountInWindow++;
                ans++;
            }
        }
        return ans;
    }
};