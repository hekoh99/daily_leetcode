class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int, int>> all;
        if (nums.size() == 1) {
            ans.push_back(nums[0][0]);
            ans.push_back(nums[0][0]);
            return ans;
        }
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums[i].size();j++) {
                all.push_back({nums[i][j], i});
            }
        }
        sort(all.begin(), all.end());

        deque<pair<int, int>> dq;
        vector<int> appear(nums.size(), 0);
        int count = 0;
        int minRange = all[all.size() - 1].first - all[0].first + 1;
        for(int i=0;i<all.size();i++) {
            if (appear[all[i].second] == 0) {
                count++;
            }
            appear[all[i].second]++;
            while (!dq.empty() && appear[dq.front().second] > 1) {
                appear[dq.front().second]--;
                dq.pop_front();
            }
            if (count == nums.size()) {
                int newRange = all[i].first - dq.front().first;
                if (newRange < minRange) {
                    minRange = newRange;
                    ans.clear();
                    ans.push_back(dq.front().first);
                    ans.push_back(all[i].first);
                }
            }
            dq.push_back(all[i]);
        }
        return ans;
    }
};