class Solution {
private:
    int getBitOfPosition(int x, int pos) {
        return (x >> pos) & 1;
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allXor = 0;
        for(int i=0;i<nums.size();i++) {
            allXor ^= nums[i];
        }
        
        int pos = 0;
        while (getBitOfPosition(allXor, pos) == 0)
            pos++;
        
        int x = 0;
        for(int i=0;i<nums.size();i++) {
            if (getBitOfPosition(nums[i], pos) == 1) {
                x ^= nums[i];
            }
        }
        int y = allXor ^ x;
        return {x, y};
    }
};