class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans = 0;
        int n = chalk.size();
        long sum = 0;
        for(int i=0;i<chalk.size();i++) {
            sum += chalk[i];
        }
        k = k % sum ;
        while(chalk[ans] <= k) {
            k -= chalk[ans];
            ans = (ans + 1) % n;
        }
        return ans;
    }
};