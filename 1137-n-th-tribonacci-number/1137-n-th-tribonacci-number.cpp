class Solution {
public:
    int tribonacci(int n) {
        vector<long> tribo;
        tribo.push_back(0);
        tribo.push_back(1);
        tribo.push_back(1);

        for(int i=0;i<n + 1;i++) {
            tribo.push_back(tribo[i] + tribo[i + 1] + tribo[i + 2]);
        }
        return tribo[n];
    }
};