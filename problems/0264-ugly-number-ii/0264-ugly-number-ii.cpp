class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> includes;
        int count = 0;
    
        includes.insert(1);
        long ugly;

        for(int i=0;i<n;i++) {
            ugly = *includes.begin();
            includes.erase(includes.begin());

            includes.insert(ugly * 2);
            includes.insert(ugly * 3);
            includes.insert(ugly * 5);
        }
        return ugly;
    }
};