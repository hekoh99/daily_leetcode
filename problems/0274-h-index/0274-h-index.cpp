class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        int tmp = 0;
        for(int i=0;i<citations.size();i++) {
            tmp = citations.size() - i > citations[i] ? citations[i] : citations.size() - i;
            if (tmp > ans)
                ans = tmp;
        }
        return ans;
    }
};