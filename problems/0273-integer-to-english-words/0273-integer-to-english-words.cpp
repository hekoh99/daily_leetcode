class Solution {
private:
    map<int, string> numbers;
    map<int, string> digits;
    map<int, string> decimal;

private:
    void init() {
        numbers[1] = "One";
        numbers[2] = "Two";
        numbers[3] = "Three";
        numbers[4] = "Four";
        numbers[5] = "Five";
        numbers[6] = "Six";
        numbers[7] = "Seven";
        numbers[8] = "Eight";
        numbers[9] = "Nine";
        numbers[10] = "Ten";
        numbers[11] = "Eleven";
        numbers[12] = "Twelve";
        numbers[14] = "Fourteen";

        digits[100] = "Hundred";
        digits[1000] = "Hundred";
        digits[1000000] = "Million";
        digits[1000000000] = "Billion";

        decimal[2] = "Twen";
        decimal[3] = "Thir";
        decimal[4] = "For";
        decimal[5] = "Fif";
        decimal[6] = "Six";
        decimal[7] = "Seven";
        decimal[8] = "Eigh";
        decimal[9] = "Nine";
    }

    string getThousandString(int num) {
        string str;
        int div = 1000;
        int share = 0;

        while (num > 0) {            
            share = num / div;
            num = num % div;

            if (share == 0) {
                div = div / 10;
                continue;
            }

            if (div == 1) {
                str.append(numbers[share]);
            }
            else if (div == 10) {
                if (share == 1 && (num == 0 || num == 1 || num == 2 || num == 4)) {
                    str.append(numbers[num + share * 10]);
                    break;
                }
                else if (share == 1) {
                    str.append(decimal[num]);
                    str.append("teen");
                    break;
                }
                else {
                    str.append(decimal[share]);
                    str.append("ty");
                }
            }
            else {
                str.append(numbers[share]);
                str.append(" ");
                str.append(digits[div]);
            }
            if (num != 0) {
                str.append(" ");
            }
            div = div / 10;
        }

        return str;
    }
public:
    string numberToWords(int num) {
        string ans;

        if (num == 0) {
            return "Zero";
        }
        
        int count = 0;
        string tmp;
        init();
        while (num > 0) {
            if (num % 1000 != 0) {
                if (ans.length() != 0) {
                    ans = " " + ans;
                }
                if (count == 1) {
                    ans = " Thousand" + ans;
                }
                else if (count == 2) {
                    ans = " Million" + ans;
                }
                else if (count == 3) {
                    ans = " Billion" + ans;
                }
            }
            tmp = getThousandString(num % 1000);
            tmp.append(ans);
            ans = tmp;
            num = num / 1000;
            count++;
        }
        
        return ans;

    }
};