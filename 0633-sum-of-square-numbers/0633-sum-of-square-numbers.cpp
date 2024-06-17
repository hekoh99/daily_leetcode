class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrtRoot = floor(sqrt(c));
        for(int i=0;i<=sqrtRoot;i++) {
            int tmp = c - (i * i);
            double root = sqrt(tmp);
            if (root - floor(root) == 0) {
                return true;
            }
        }
        return false;
    }
};