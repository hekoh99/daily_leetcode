class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_set<int> prefix;
        int val;
        for(int i=0;i<arr1.size();i++) {
            val = arr1[i];
            while (prefix.find(val) == prefix.end() && val > 0) {
                prefix.insert(val);
                val = val / 10;
            }
        }

        for(int i=0;i<arr2.size();i++) {
            val = arr2[i];
            while (prefix.find(val) == prefix.end() && val > 0) {
                val = val / 10;
            }
            if (val > 0) {
                if (ans < to_string(val).length()) {
                    ans = to_string(val).length();
                }
            }
        }

        return ans;
    }
};