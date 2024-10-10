class MovingAverage {
public:
    int sum = 0, capacity = 0;
    queue<int> nums;
    MovingAverage(int size) {
        capacity = size;
    }

    double next(int val) {
        nums.push(val);
        sum += val;
        if (nums.size() > capacity) {
            sum -= nums.front();
            nums.pop();
        }
        return (double)sum / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */