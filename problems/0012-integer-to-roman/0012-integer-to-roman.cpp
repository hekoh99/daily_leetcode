class Solution {
public:
    string intToRoman(int num) {
        string ans;
        map<int, char, greater<int>> romanInteger;
        
        romanInteger[1000] = 'M';
        romanInteger[500] = 'D';
        romanInteger[100] = 'C';
        romanInteger[50] = 'L';
        romanInteger[10] = 'X';
        romanInteger[5] = 'V';
        romanInteger[1] = 'I';

        map<int, char, greater<int>>::iterator it;
        int share = 0, leftover = 0, mul = 1000;
        while (num > 0) {
            share = num / mul;
            leftover = num % mul;

            if (share == 0) {
                mul = mul / 10;
                continue;
            }
            if (share == 9) {
                ans += romanInteger[mul];
                ans += romanInteger[mul * 10];
            }
            else if (share >= 5) {
                ans += romanInteger[mul * 5];
                for(int i=0;i<share - 5;i++) {
                    ans += romanInteger[mul];
                }
            }
            else if (share == 4) {
                ans += romanInteger[mul];
                ans += romanInteger[mul * 5];
            }
            else {
                for(int i=0;i<share;i++) {
                    ans += romanInteger[mul];
                }
            }
            mul = mul / 10;
            num = leftover;
        }
        return ans;
    }
};