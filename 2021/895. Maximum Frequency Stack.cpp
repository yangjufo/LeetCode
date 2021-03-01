class FreqStack {
public:
    vector<vector<int>> freqStack;
    unordered_map<int, int> freqMap;
    FreqStack() {        
    }
    
    void push(int x) {  
        int freq = 1;
        if (freqMap.find(x) != freqMap.end()) {
            freq = freqMap[x] + 1;            
        }
        freqMap[x] = freq;
        
        if (freq > freqStack.size()) {
            freqStack.push_back({});
        }
        freqStack[freq - 1].push_back(x);        
    }
    
    int pop() {        
        int val = freqStack.back().back();
        freqStack.back().pop_back();
        if (freqStack.back().empty()) {
            freqStack.pop_back();
        }
        freqMap[val] -= 1;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */