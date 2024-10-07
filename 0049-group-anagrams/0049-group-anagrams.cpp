class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, int> posMap;
        string tmp;
        for(int i=0;i<strs.size();i++) {
            tmp.assign(strs[i]);
            sort(tmp.begin(), tmp.end());
            if (posMap.find(tmp) == posMap.end()) {
                posMap[tmp] = ans.size();
                ans.push_back({strs[i]});
            }
            else {
                ans[posMap[tmp]].push_back(strs[i]);
            }
        }
        return ans;
    }
};