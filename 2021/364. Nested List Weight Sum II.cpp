/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int allDepth = getDepth(nestedList);        
        return getSum(nestedList, allDepth);
    }
    
    int getDepth(vector<NestedInteger>& nestedList) {
        int depth = 1;
        for (auto nested : nestedList) {
            if (!nested.isInteger()) {
                depth = max(getDepth(nested.getList()) + 1, depth);
            }
        }                                
        return depth;
    }
    
    int getSum(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto nested : nestedList) {
            if (nested.isInteger()) {
                sum += nested.getInteger() * depth;
            } else {
                sum += getSum(nested.getList(), depth - 1);
            }
        }
        return sum;
    }
    
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, sum = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (auto nested : nestedList) {
                if (nested.isInteger()) {
                    unweighted += nested.getInteger();
                } else {
                    nextLevel.insert(nextLevel.end(), nested.getList().begin(), nested.getList().end());
                }
            }
            sum += unweighted;
            nestedList = nextLevel;
        }
        return sum;
    }
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0;
        for (NestedInteger& ni : nestedList) {
            maxDepth = max(maxDepth, getMaxDepth(ni));
        }           
        int sum = 0;
        for (NestedInteger& ni : nestedList) {
            sum += getSum(ni, maxDepth, 1);
        }
        return sum;
    }
    
    int getSum(NestedInteger& nestedInt, int maxDepth, int currDepth) {
        if (nestedInt.isInteger()) {
            return nestedInt.getInteger() * (maxDepth - currDepth + 1);
        }
        int sum = 0;
        for (NestedInteger& ni : nestedInt.getList()) {
            sum += getSum(ni, maxDepth, currDepth + 1);
        }
        return sum;
    }
    
    int getMaxDepth(NestedInteger& nestedInt) {
        if (nestedInt.isInteger()) {
            return 1;
        }
        int res = 1;
        for (NestedInteger& ni : nestedInt.getList()) {
            res = max(res, 1 + getMaxDepth(ni));
        }
        return res;
    }
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:    
    int sum = 0;    
    int depthSumInverse(vector<NestedInteger>& nestedList) {               
        dfs(nestedList, 0);
        return sum;
    }
    
    void dfs(vector<NestedInteger>& nestedList, int weight) {
        if (nestedList.empty()) return;
        vector<NestedInteger> nextList;
        for (NestedInteger& ni : nestedList) {
            if (ni.isInteger()) {
                weight += ni.getInteger();
            } else {
                nextList.insert(nextList.end(), ni.getList().begin(), ni.getList().end());
            }
        }
        sum += weight;
        dfs(nextList, weight);
    }
    
};

class Solution {
public:        
    int depthSumInverse(vector<NestedInteger>& nestedList) {               
        int sum = 0, weight = 0;
        while (!nestedList.empty()) {            
            vector<NestedInteger> nextList;
            for (NestedInteger& ni : nestedList) {
                if (ni.isInteger()) {
                    weight += ni.getInteger();
                } else {
                    nextList.insert(nextList.end(), ni.getList().begin(), ni.getList().end());
                }
            }
            sum += weight;
            nestedList = nextList;
        }
        return sum;
    }
};