/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flatternList;
    int index = 0;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    void dfs(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                flatternList.push_back(nestedList[i].getInteger());
            } else {
                dfs(nestedList[i].getList());
            }
        }
    }
    
    int next() {
        index++;
        return flatternList[index - 1];
    }
    
    bool hasNext() {
        return index < flatternList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:    
    stack<pair<vector<NestedInteger>, int>> lists;    
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        lists.push({nestedList, 0});
    }        
    
    int next() {        
        if (!hasNext()) return -1;
        int currIndex = lists.top().second;
        vector<NestedInteger> currList = lists.top().first;
        lists.pop();
        lists.push({currList, currIndex + 1});
        return currList[currIndex].getInteger();
    }
    
    bool hasNext() {
        while (!lists.empty()) {
            if (lists.top().second >= lists.top().first.size()) {
                lists.pop();
                continue;
            }
           
            int currIndex = lists.top().second;
            vector<NestedInteger> currList = lists.top().first;
           
            if (currList[currIndex].isInteger()) break;
           
            lists.pop();
            lists.push({currList, currIndex + 1});
           
            lists.push({currList[currIndex].getList(), 0});                      
        }
        return !lists.empty();                                  
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */