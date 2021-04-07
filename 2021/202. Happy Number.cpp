class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int tmp = 0;
            while (n != 0) {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = tmp;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        int fast = getNext(n), slow = n;
        while (slow != fast && fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
    
    int getNext(int n) {
        int next = 0;
        while (n > 0) {
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        return next;
    }
};