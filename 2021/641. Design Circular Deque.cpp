class MyCircularDeque {
public:
    int size;
    deque<int> dq;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (dq.size() >= size) {
            return false;
        }
        dq.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (dq.size() >= size) {
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (dq.empty()) {
            return false;
        }
        dq.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (dq.empty()) {
            return false;
        }
        dq.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (dq.empty()) {
            return -1;
        }
        return dq.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (dq.empty()) {
            return -1;
        }
        return dq.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return dq.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return dq.size() == size;
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

class MyCircularDeque {
public:
    vector<int> dq;
    int cnt, k, front, rear;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->k = k;
        cnt = 0;
        front = k - 1;
        rear = 0;
        dq.resize(k, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cnt == k) {
            return false;
        }
        dq[front] = value;
        front = (front - 1 + k) % k;
        cnt++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cnt == k) {
            return false;
        }
        dq[rear] = value;
        rear = (rear + 1) % k;
        cnt++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (cnt == 0) {
            return false;
        }
        front = (front + 1) % k;
        cnt--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (cnt == 0) {
            return false;
        }
        rear = (rear - 1 + k) % k;
        cnt--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (cnt == 0) {
            return -1;
        }
        return dq[(front + 1) % k];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (cnt == 0) {
            return -1;
        }
        return dq[(rear - 1 + k) % k];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == k;
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