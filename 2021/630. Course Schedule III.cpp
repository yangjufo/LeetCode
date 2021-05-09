class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& left, vector<int>& right) {
            return (left[1] == right[1]) ? left[0] < right[0] : left[1] < right[1];
        });
        priority_queue<int> durations;
        int totalTime = 0, totalClass = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (totalTime + courses[i][0] > courses[i][1]) {
                if (!durations.empty() && courses[i][0] < durations.top()) {
                    totalTime -= durations.top();
                    durations.pop();
                    totalClass -= 1;
                } else {
                    continue;
                }
            }            
            durations.push(courses[i][0]);
            totalTime += courses[i][0];
            totalClass += 1;            
        }
        return totalClass;
    }
};
