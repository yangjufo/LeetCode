class MaxStack {
public:
    stack<int> valStack, maxStack;
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        valStack.push(x);
        if (!maxStack.empty() && maxStack.top() > x) {
            maxStack.push(maxStack.top());
        } else {
            maxStack.push(x);
        }
    }
    
    int pop() {
        maxStack.pop();
        int popVal = valStack.top();
        valStack.pop();
        return popVal;
    }
    
    int top() {
        return valStack.top();
    }
    
    int peekMax() {
        return maxStack.top();
    }
    
    int popMax() {        
        int popVal = maxStack.top();
        stack<int> buffer;
        while (top() != popVal) {
            buffer.push(pop());
        }
        pop();
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        return popVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

class Node {
public:
    int val;
    Node *prev, *next;
    
    Node(int _val): val(_val), prev(NULL), next(NULL) {}
};

class DbList {
public:
    Node *head, *tail;
    
    DbList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void insert(Node* node) {   
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;        
        tail->prev = node;
    }
    
    void erase(Node* node) {        
        node->prev->next = node->next;
        node->next->prev = node->prev;        
    }       
    
    Node* top() {
        return tail->prev;
    }
    
    bool empty() {
        return head->next == tail;
    }
};

class MaxStack {
public:    
    
    DbList* stackList = new DbList();
    map<int, vector<Node*>, greater<int>> maxMap;
    
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        Node* node = new Node(x);
        stackList->insert(node);
        maxMap[x].push_back(node);
    }
    
    int pop() {
        if (stackList->empty()) return -1;
        
        Node* node = stackList->top();
        int val = node->val;
        
        stackList->erase(node);
        maxMap[val].pop_back();
        if (maxMap[val].empty()) {
            maxMap.erase(val);
        }
        delete node;
        
        return val;
    }
    
    int top() {
        if (stackList->empty()) return -1;        
        return stackList->top()->val;
    }
    
    int peekMax() {
        if (stackList->empty()) return -1;
        return maxMap.begin()->second.back()->val;
    }
    
    int popMax() {
        if (stackList->empty()) return -1;
        
        Node* node = maxMap.begin()->second.back();
        int val = node->val;
        
        stackList->erase(node);
        maxMap[val].pop_back();
        if (maxMap[val].empty()) {
            maxMap.erase(val);
        }
        delete node;
        
        return val;
    }
    
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */