class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first, second;
        int bigPoint, smallPoint;
        int ans = 0;
        if (x > y) {
            first = "ab";
            second = "ba";
            bigPoint = x;
            smallPoint = y;
        }
        else {
            first = "ba";
            second = "ab";
            bigPoint = y;
            smallPoint = x;
        }
        
        int index = 0;
        while (index < s.length()) {
            if (s.substr(index, 2) == first) {
                ans += bigPoint;
                s.erase(index, 2);
                if (index > 0) {
                    index--;
                }
            }
            else
                index++;
        }
        
        index = 0;
        while (index < s.length()) {
            if (s.substr(index, 2) == second) {
                ans += smallPoint;
                s.erase(index, 2);
                if (index > 0) {
                    index--;
                }
            }
            else
                index++;
        }
        return ans;
    }
};