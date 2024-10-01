class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        bool ans = true;
        vector<int> tmp;
        for(int i=0;i<arr.size();i++) {
            arr[i] = arr[i] % k;
            if (arr[i] < 0) {
                arr[i] += k;
            }
            if (arr[i] != 0) {
                tmp.push_back(arr[i]);
            }
        }
        sort(tmp.begin(), tmp.end());
        int count = 0;
        if (tmp.size() % 2 != 0)
            return false;
        
        for(int i=0;i<tmp.size()/2;i++) {
            if (tmp[i] + tmp[tmp.size() - i - 1] != k) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};