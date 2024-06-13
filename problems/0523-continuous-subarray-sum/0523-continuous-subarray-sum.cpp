class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int flag = false;
        map<int, vector<int>> sumMode;
        long long sum = 0;
        vector<int> prevIndex;
        map<int, vector<int>>::iterator it;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            sum = sum % k;
            if (sum == 0 && i > 0) {
                flag = true;
                break;
            }
            it = sumMode.find(sum); 
            if (it == sumMode.end()) {
                prevIndex.push_back(i);
                sumMode.insert(make_pair(sum, prevIndex));
                prevIndex.clear();
            }
            else {
                (*it).second.push_back(i);
                vector<int> tmp = (*it).second;
                for(int j = 0;j<tmp.size();j++) {
                    if (i - tmp[j] > 1) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        return flag;
    }
};