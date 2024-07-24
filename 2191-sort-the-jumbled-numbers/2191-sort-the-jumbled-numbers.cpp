class Solution {
private:
    int convert(int num, vector<int>& order) {
        int res = 0;
        long long mul = 1;

        if (num == 0)
            return order[0];
        while (num > 0) {
            res += (order[num % 10] * mul);
            num = num / 10;
            mul *= 10;
        }
        return res;
    }

    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> tmp;
        for(int i=0;i<nums.size();i++) {
            tmp.push_back(make_pair(nums[i], convert(nums[i], mapping)));
        }
        sort(tmp.begin(), tmp.end(), comp);
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            ans.push_back(tmp[i].first);
        }
        return ans;
    }
};