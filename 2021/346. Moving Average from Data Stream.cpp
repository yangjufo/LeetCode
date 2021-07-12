class MovingAverage {
public:
    /** Initialize your data structure here. */
    deque<int> nums;
    int size, sum;
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        nums.push_back(val);
        sum += val;
        if (nums.size() > size) {            
            sum -= nums.front();
            nums.pop_front();
        }
        return (double)sum / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */