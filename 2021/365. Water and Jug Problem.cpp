class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug1Capacity > jug2Capacity) {
            swap(jug1Capacity, jug2Capacity);
        }
        queue<pair<int, int>> queue;
        unordered_map<int, unordered_set<int>> visited;
        queue.push({0, 0});
        visited[0].insert(0);
        while (!queue.empty()) {
            int a = queue.front().first, b = queue.front().second;
            queue.pop();
            if (a + b == targetCapacity) return true;            
            addState(visited, queue, 0, b);
            addState(visited, queue, a, 0);
            addState(visited, queue, jug1Capacity, b);
            addState(visited, queue, a, jug2Capacity);
            addState(visited, queue, min(a + b, jug1Capacity), a + b > jug1Capacity ? b - (jug1Capacity - a) : 0);
            addState(visited, queue, a + b > jug2Capacity ? a - (jug2Capacity - b) : 0, min(a + b, jug2Capacity));
        }
        return false;
    }
    
    void addState(unordered_map<int, unordered_set<int>>& visited, queue<pair<int, int>>& queue, int left, int right) {
        if (visited.find(left) == visited.end() || visited[left].find(right) == visited[left].end()) {
            queue.push({left, right});
            visited[left].insert(right);
        }
    }
};

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        //case x or y is zero
        if( x == z || y == z || x + y == z ) return true;

        //get GCD, then we can use the property of Bézout's identity
        return z%gcd(x, y) == 0;
    }
};