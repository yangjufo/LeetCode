class Solution {
public:
    void addState(queue<array<int, 2>>& queue, unordered_map<int, unordered_set<int>>& visited, int jug1, int jug2) {
        if (visited.find(jug1) == visited.end() || visited[jug1].find(jug2) == visited[jug1].end()) {
            queue.push({jug1, jug2});
            visited[jug1].insert(jug2);
        }
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        if (jug1Capacity > jug2Capacity) {
            swap(jug1Capacity, jug2Capacity);
        }
        queue<array<int, 2>> queue;
        unordered_map<int, unordered_set<int>> visited;
        queue.push({0, 0});
        visited[0].insert(0);
        while (!queue.empty()) {
            int jug1 = queue.front()[0], jug2 = queue.front()[1];
            queue.pop();
            if (jug1 + jug2 == targetCapacity) {
                return true;
            }
            addState(queue, visited, jug1, 0);
            addState(queue, visited, 0, jug2);
            addState(queue, visited, jug1Capacity, jug2);
            addState(queue, visited, jug1, jug2Capacity);
            addState(queue, visited, min(jug1 + jug2, jug1Capacity), jug1 + jug2 > jug1Capacity ? jug2 - (jug1Capacity - jug1) : 0);
            addState(queue, visited, jug1 + jug2 > jug2Capacity ? jug1 - (jug2Capacity - jug2) : 0, min(jug1 + jug2, jug2Capacity));
        }
        return false;
    }
};