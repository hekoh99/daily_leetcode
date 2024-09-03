class Solution {
private:
    int findNumber(vector<int>& numbers, int target, int s) {
        int index = -1;
        int e = numbers.size() - 1;
        int mid;
        while (s <= e) {
            mid = (s + e) / 2;
            if (numbers[mid] == target) {
                index = mid;
                break;
            }
            else if (numbers[mid] > target){
                e = mid - 1; 
            }
            else {
                s = mid + 1;
            }
        }
        return index;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left;
        int j = 0;
        int index = 0;
        vector<int> ans;
        for(int i=0;i<numbers.size();i++) {
            left = target - numbers[i];
            j = i + 1;
            index = findNumber(numbers, left, j);
            if (index != -1) {
                ans.push_back(i + 1);
                ans.push_back(index + 1);
                break;
            }
        }
        return ans;
    }
};