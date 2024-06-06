class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int totalSize = hand.size();
        if (totalSize % groupSize != 0) {
            return false;
        }
        map<int, int> orderPair;
        map<int, int>::iterator it;
        for(int i=0;i<hand.size();i++) {
            it = orderPair.find(hand[i]); 
            if (it == orderPair.end()) {
                orderPair.insert(make_pair(hand[i], 1));
            }
            else {
                orderPair[hand[i]]++;
            }
        }
        bool flag = true;
        int count = 0;
        int prev = -1;
        while (!orderPair.empty()) {
            count = 0;
            it = orderPair.begin();
            while (count < groupSize && it != orderPair.end()) {

                if (count != 0) {
                    if (prev + 1 != (*it).first) {
                        flag = false;
                        break;
                    }
                }
                prev = (*it).first;
                (*it).second--;
                count++;
                if ((*it).second == 0) {
                    it = orderPair.erase(it);
                }
                else {
                    it++;
                }
            }
            if (!flag || count != groupSize) {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};