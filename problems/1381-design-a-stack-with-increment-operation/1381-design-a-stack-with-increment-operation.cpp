class CustomStack {
private:
    vector<int> stack;
    int capacity;
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if (stack.size() >= capacity)
            return ;
        stack.push_back(x);
    }
    
    int pop() {
        if (stack.empty())
            return -1;
        int res = stack.back();
        stack.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        if (stack.size() < k)
            k = stack.size();
        for(int i=0;i<k;i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */