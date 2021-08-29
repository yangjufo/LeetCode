class MyQueue {
public:
    stack<int> s1, s2;    
    /** Initialize your data structure here. */
    MyQueue() {        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {                
        int val = peek();
        s2.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
public:
    stack<int> nums;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!nums.empty()) {
            tmp.push(nums.top());
            nums.pop();
        }
        nums.push(x);
        while (!tmp.empty()) {
            nums.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = -1;
        if (!nums.empty()) {
            val = nums.top();
            nums.pop();
        }
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return nums.empty() ? -1 : nums.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */