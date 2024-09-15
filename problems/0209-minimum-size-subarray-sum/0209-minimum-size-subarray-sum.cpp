class Solution {
private:
    bool isPossible(int target, vector<int>& arr, int winSize) {
        int sum = 0;
        bool flag = false;
        for(int i=0;i<winSize;i++) {
            sum += arr[i];
        }
        if (sum >= target) {
            flag = true;
        }
        for(int i=winSize;i<arr.size();i++) {
            sum -= arr[i - winSize];
            sum += arr[i];
            if (sum >= target) {
                flag = true;
                break;
            }
        }
        return flag;
    }

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start, end, mid;
        int ans = 0;

        start = 1;
        end = nums.size();
        while (start <= end) {
            mid = (start + end) / 2;
            if (isPossible(target, nums, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};