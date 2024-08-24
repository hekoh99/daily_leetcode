class Solution {
private:
    long long makePalindrome(long long num) {
        string res = to_string(num);
        for(int i=0;i<res.length();i++) {
            res[res.length() - i - 1] = res[i];
        }
        return stoll(res);
    }

public:
    string nearestPalindromic(string n) {
        string ans;
        long long prev = 0;
        long long next = 0;
        long long s = 0, e = stoll(n), m;
        long long target = stoll(n);
        long long pal;
        while (s <= e) {
            m = (e - s) / 2 + s;
            pal = makePalindrome(m);
            if (pal < target) {
                prev = pal;
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        s = stoll(n);
        e = 1e18;
        while (s <= e) {
            m = (e - s) / 2 + s;
            pal = makePalindrome(m);
            if (pal > target) {
                next = pal;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        if ((target - prev) <= (next - target)) {
            return to_string(prev);
        }
        return to_string(next);
    }
};