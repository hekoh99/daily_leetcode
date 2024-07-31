class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> nhMap;
        for(int i=0;i<names.size();i++) {
            nhMap[heights[i]] = names[i];
        }
        vector<string> ans;
        
        map<int, string, greater<int>>::iterator it;
        for(it = nhMap.begin();it != nhMap.end();it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};