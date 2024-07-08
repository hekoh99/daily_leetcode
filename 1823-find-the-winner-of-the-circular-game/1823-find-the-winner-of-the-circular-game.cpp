class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> circle;

        for(int i=1;i<=n;i++) {
            circle.push_back(i);
        }
        list<int>::iterator it = circle.begin();
        while (circle.size() > 1) {
            for(int i=0;i<k-1;i++) {
                if (it == circle.end()) {
                    it = circle.begin();
                }
                it++;
                if (it == circle.end()) {
                    it = circle.begin();
                }
            }
            it = circle.erase(it);
        }
        return circle.front();
    }
};