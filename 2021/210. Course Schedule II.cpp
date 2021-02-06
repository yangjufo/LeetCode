class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);
        unordered_map<int, vector<int>> edges;
        for (vector<int>& pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            degrees[pre[0]]++;
        }
        
        queue<int> takeQueue;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                takeQueue.push(i);
            }
        }
        
        vector<int> courses;
        while (!takeQueue.empty()) {
            int takeCourse = takeQueue.front();
            takeQueue.pop();
            courses.push_back(takeCourse);
            
            for (int next : edges[takeCourse]) {
                degrees[next]--;
                if (degrees[next] == 0) {
                    takeQueue.push(next);
                }
            }
        }   
        
        if (courses.size() < numCourses) {
            courses.clear();
        }
        
        return courses;
    }
};