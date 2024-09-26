class MyCalendar {
private:
    vector<pair<int, int>> condition;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool flag = true;
        for(int i=0;i<condition.size();i++) {
            if (!(condition[i].first >= end || condition[i].second <= start)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            condition.push_back(make_pair(start, end));
        }
        return flag;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */