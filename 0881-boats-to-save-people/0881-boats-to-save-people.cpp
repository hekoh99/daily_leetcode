class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0;
        int small = 0, big = people.size() - 1;
        while (small < big) {
            if (people[small] + people[big] <= limit) {
                boat++;
                small++;
                big--;
            }
            else {
                big--;
                boat++;
            }
        }
        if (small == big)
            boat++;
        return boat;
    }
};