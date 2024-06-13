class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = k;
        int count = 0;
        for (int n : nums) {
            finalXor = finalXor ^ n;
        }
        
        for(int i=0;i<4 * 8;i++) {
            int tmp = finalXor >> i & 1;
            if(tmp == 1)
		        count++;
        }
        return count;
    }
};