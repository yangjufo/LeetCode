/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int sum = 0;
    
    private void getSum(TreeNode root, int curr) {
        if (root == null) return;
        if (root.left == null && root.right == null) sum += curr * 10 + root.val;
        else {
            getSum(root.left, curr * 10 + root.val);
            getSum(root.right, curr * 10 + root.val);
        }
    }
    
    public int sumNumbers(TreeNode root) {
        getSum(root, 0);
        return sum;
    }
}