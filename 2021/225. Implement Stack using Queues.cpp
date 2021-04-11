class MyStack {
public:
    queue<int> *in, *out;
    /** Initialize your data structure here. */
    MyStack() {
        in = new queue<int>();
        out = new queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!out->empty()) {
            in->push(out->front());
            out->pop();
        }
        in->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        out->pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {               
        if (out->empty()) {
            while (in->size() > 1) {
                out->push(in->front());
                in->pop();
            }
            queue<int>* tmp = in;
            in = out;
            out = tmp;
        }
        return out->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return in->empty() && out->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    queue<int> *q1, *q2;
    int topVal;
    /** Initialize your data structure here. */
    MyStack() {
        q1 = new queue<int>();
        q2 = new queue<int>();        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1->push(x);
        topVal = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q1->size() > 1) {
            topVal = q1->front();
            q2->push(topVal);
            q1->pop();
        }
        int val = q1->front();
        q1->pop();
        swap(q1, q2);
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return topVal;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    queue<int> valQueue;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        valQueue.push(x);
        int size = valQueue.size();
        while (size > 1) {
            valQueue.push(valQueue.front());
            valQueue.pop();
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topVal = valQueue.front();
        valQueue.pop();
        return topVal;
    }
    
    /** Get the top element. */
    int top() {
        return valQueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return valQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */