class Solution {
private:
    int getRow(int index, int numRows, int prev) {
        if (numRows == 1)
            return 0;

        if (index % (numRows - 1) == 0 && (index / (numRows - 1)) % 2 == 0)
            return 0;
        if (index % (numRows - 1) == 0 && (index / (numRows - 1)) % 2 == 1) {
            return (numRows - 1);
        }
        if ((index / (numRows - 1)) % 2 == 0) {
            return prev + 1;
        }
        if ((index / (numRows - 1)) % 2 == 1) {
            return prev - 1;
        }
        return 0;
    }
public:
    string convert(string s, int numRows) {
        vector<string> zigzag(numRows);
        int row = 0;
        int prev = 0;
        for(int i=0;i<s.length();i++) {
            row = getRow(i, numRows, prev);
            zigzag[row] += s[i];
            prev = row;
        }
        string ans;
        for(int i=0;i<zigzag.size();i++) {
            ans.append(zigzag[i]);
        }
        return ans;
    }
};