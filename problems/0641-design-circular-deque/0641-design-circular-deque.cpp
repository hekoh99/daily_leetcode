class MyCircularDeque {
    vector<int> dq;
    int capacity;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        dq.assign(capacity, 0);
        front = 0;
        rear = 0;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        dq[front] = value;
        front = (front + capacity - 1) % capacity;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        dq[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear = (rear + capacity - 1) % capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return dq[(front + 1) % capacity];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */