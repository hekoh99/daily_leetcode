class Solution {
private:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
        }
        vector<pair<int, int>> sorted;
        sorted.assign(freq.begin(), freq.end());
        sort(sorted.begin(), sorted.end(), comp);
        
        vector<int> ans;
        for(int i=0;i<sorted.size();i++) {
            for(int j=0;j<sorted[i].second;j++) {
                ans.push_back(sorted[i].first);
            }
        }
        return ans;
    }
};