class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int count = 0;
        unordered_set<int> keys = {0};
        while (!keys.empty()) {
            unordered_set<int> newKeys;
            for (int key : keys) {
                visited[key] = true;                
                for (int room : rooms[key]) {                    
                    if (!visited[room]) {
                        newKeys.insert(room);
                    }
                }                                
            }
            keys = newKeys;
        }
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);        
        stack<int> roomStack;
        roomStack.push(0);
        while (!roomStack.empty()) {
            int r = roomStack.top();
            roomStack.pop();
            visited[r] = true;
            for (int next : rooms[r]) {
                if (!visited[next]) {                    
                    roomStack.push(next);
                }
            }
        }
        
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(visited, rooms, 0);
        return visited.size() == rooms.size();
    }
    
    void dfs(unordered_set<int>& visited, vector<vector<int>>& rooms, int index) {
        if (visited.find(index) != visited.end()) return;
        visited.insert(index);
        for (int key : rooms[index]) {
            dfs(visited, rooms, key);
        }
    }
};