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