class MyCircularQueue {
public:
    int* nums;
    int front, rear, size;
    MyCircularQueue(int k) {
        nums = new int[k + 1];
        front = rear = 0;
        size = k + 1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        nums[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return nums[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return nums[(rear - 1 + size) % size];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */