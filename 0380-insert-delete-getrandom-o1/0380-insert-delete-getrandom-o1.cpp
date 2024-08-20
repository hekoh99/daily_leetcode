class RandomizedSet {
private:
    unordered_map<int, int> position;
    vector<int> rs;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (position.find(val) == position.end()) {
            rs.push_back(val);
            position[val] = rs.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (position.find(val) != position.end()) {
            int targetPos = position[val];
            rs[targetPos] = rs.back();
            position[rs.back()] = targetPos;
            rs.pop_back();
            position.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int step = rand() % rs.size();
        return rs[step];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */