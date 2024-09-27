class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<overlapBookings.size();i++) {
            if (isOverlapped(overlapBookings[i].first, overlapBookings[i].second, start, end)) {
                return false;
            }
        }

        for(int i=0;i<bookings.size();i++) {
            if (isOverlapped(bookings[i].first, bookings[i].second, start, end)) {
                overlapBookings.push_back(getOverlapped(bookings[i].first, bookings[i].second, start, end));
            }
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }

    bool isOverlapped(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */