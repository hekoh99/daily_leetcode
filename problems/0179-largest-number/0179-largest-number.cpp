class Solution {
private:
    static bool compare(string &a, string &b){
        return a + b > b + a;
    }

public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> tmp;
        for(int i=0;i<nums.size();i++) {
            tmp.push_back(to_string(nums[i]));
        }
        sort(tmp.begin(), tmp.end(), compare);
        for(int i=0;i<tmp.size();i++) {
            ans.append(tmp[i]);
        }
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};