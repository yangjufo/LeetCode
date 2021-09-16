class MinStack {
public:
    
    stack<int> nums;
    stack<int> mins;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
        if (mins.empty() || x <= mins.top()) {
            mins.push(x);
        }
    }
    
    void pop() {
        int top = nums.top();
        nums.pop();
        if (mins.top() == top) {
            mins.pop();
        }
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 class MinStack {
public:
    stack<int> vals, mins;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        vals.push(val);
        if (mins.empty() || val < mins.top()) {
            mins.push(val);
        } else {
            mins.push(mins.top());
        }
    }
    
    void pop() {
        vals.pop();
        mins.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */