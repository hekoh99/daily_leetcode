class Solution {
private:
    vector<vector<int>> ans;

private:
    void findCombination(vector<int>& arr, int index, int target, int sum, vector<int>& combination) {
        if (sum == target) {
            ans.push_back(combination);
            return;
        }
        if (sum > target) {
            return ;
        }
        int left = target - sum;
        int prev = -1;
        for(int i=index + 1;i<arr.size();i++) {
            if (arr[i] <= left && prev != arr[i]) {
                combination.push_back(arr[i]);
                findCombination(arr, i, target, sum + arr[i], combination);
                combination.pop_back();
            }
            prev = arr[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        int prev = -1;
        sort(candidates.begin(), candidates.end());
        for(int i=0;i<candidates.size();i++) {
            if (candidates[i] <= target && prev != candidates[i]) {
                tmp.push_back(candidates[i]);
                findCombination(candidates, i, target, candidates[i], tmp);
                tmp.pop_back();
            }
            prev = candidates[i];
        }
        return ans;
    }
};