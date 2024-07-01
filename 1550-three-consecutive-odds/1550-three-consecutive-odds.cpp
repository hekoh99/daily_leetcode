class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = 0;
        for(int i=0;i<arr.size();i++) {
            if (arr[i] % 2 == 1)
                n++;
            else {
                n = 0;
            }
            if (n == 3) {
                return true;
            }
        }
        return false;
    }
};