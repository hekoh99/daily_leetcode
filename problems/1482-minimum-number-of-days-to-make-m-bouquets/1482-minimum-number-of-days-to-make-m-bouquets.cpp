class Solution {
private:
    int countBouquets(vector<int> bloomDay, int day, int k) {
        int count = 0;
        int total = 0;
        for(int i=0;i<bloomDay.size();i++) {
            if (bloomDay[i] - day <= 0) {
                count++;
            }
            else {
                count = 0;
            }
            if (count == k) {
                total++;
                count = 0;
            }
        }
        return total;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int min = bloomDay[0];
        int max = bloomDay[0];
        for(int i = 0;i<bloomDay.size();i++) {
            if (min > bloomDay[i]) {
                min = bloomDay[i];
            }
            if (max < bloomDay[i]) {
                max = bloomDay[i];
            }
        }
        int mid = 0;
        while (min <= max) {
            mid = min + (max-min) / 2;
            int tmp = countBouquets(bloomDay, mid, k);
            if (tmp >= m) {
                if (ans == -1 || ans > mid)
                    ans = mid;
                max = mid - 1;
            }
            else if (tmp > m) 
                max = mid - 1;      
            else 
                min = mid + 1;
        }
        return ans;
    }
};