class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    MedianFinder() {
    }

    void addNum(int num) {
        min_pq.push(num);
        max_pq.push(min_pq.top());
        min_pq.pop();
        if (max_pq.size() - min_pq.size() > 1) {
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
    }

    double findMedian() {
        if ((min_pq.size() + max_pq.size()) % 2 == 0) {
            return (double)(min_pq.top() + max_pq.top()) / 2;
        }
        return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */