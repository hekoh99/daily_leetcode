class Solution {
private:
    bool checkPosition(int m, int gap, vector<int>& position) {
        int count = 1;
        int prevPos = position[0];
        for(int i=0;i<position.size();i++) {
            if (position[i] - prevPos >= gap) {
                count++;
                prevPos = position[i];
            }
        }
        return m <= count;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int min = 1;
        int max = position[n - 1] / (m - 1) + 1;
        int mid = 0;
        int ans = 0;
        while (min <= max) {
            mid = min + (max - min) / 2;
            int tmp = checkPosition(m, mid, position);
            if (tmp == true) {
                ans = mid;
                min = mid + 1;
            }
            else {
                max = mid - 1;
            }
        }
        return ans;
    }
};