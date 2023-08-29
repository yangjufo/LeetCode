class MyStack {
public:
    queue<int> stack_queue;
    MyStack() {

    }

    void push(int x) {
        queue<int> tmp;
        while (!stack_queue.empty()) {
            tmp.push(stack_queue.front());
            stack_queue.pop();
        }
        stack_queue.push(x);
        while(!tmp.empty()) {
            stack_queue.push(tmp.front());
            tmp.pop();
        }
    }

    int pop() {
        int ret = stack_queue.front();
        stack_queue.pop();
        return ret;
    }

    int top() {
        return stack_queue.front();
    }

    bool empty() {
        return stack_queue.empty();
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