class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> countings(1001, 0);
        vector<int> ans;
        for(int i=0;i<arr1.size();i++) {
            countings[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++) {
            for(int j=0;j<countings[arr2[i]];j++) {
                ans.push_back(arr2[i]);
            } 
            countings[arr2[i]] = 0;
        }
        for(int i=0;i<1001;i++) {
            for(int j=0;j<countings[i];j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};