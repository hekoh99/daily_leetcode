class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int xorResult = 0;
        map<int, vector<int>> history;
        for(int i=0;i<arr.size();i++) {
            xorResult = xorResult ^ arr[i];
            map<int, vector<int>>::iterator it;
            it = history.find(xorResult);
            if (xorResult == 0) {
                count += i;
            }
            if(it == history.end()) {
                vector<int> tmp;
                tmp.push_back(i);
                history.insert(make_pair(xorResult, tmp));
            }
            else {
                for(int j=0;j<it->second.size();j++) {
                    count += (i - (it->second[j] + 1));
                }
                it->second.push_back(i);
            }
        }
        return count;
    }
};