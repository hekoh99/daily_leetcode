class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int size = nums.size();
        int count = 0;
        map<int, int> prevs;
        map<int, int>::iterator it;
        for(int i=0;i<size;i++) {
            sum += nums[i];
            sum = sum % k;
            if (sum < 0)
                sum += k;
            if (sum == 0)
                count++;
           
            it = prevs.find(sum);
            if (it == prevs.end()) {
                prevs.insert(make_pair(sum, 1));
            }
            else {
                count += (*it).second;
                (*it).second++;
            }
        }
        return count;
    }
};