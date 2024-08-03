class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        k = k % nums.size();
        for(int i=0;i<nums.size();i++) {
            tmp.push_back(nums[(i + nums.size() - k) % nums.size()]);
        }
        nums.assign(tmp.begin(), tmp.end());
    }
};