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
    TreeNode x = null, y = null, pred = null;
    
    private void swap(TreeNode a, TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }
    
    private void findTwoSwapped(TreeNode root) {
        if (root == null) return;
        findTwoSwapped(root.left);
        if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null)
                x = pred;
            else return;
        }
        pred = root;
        findTwoSwapped(root.right);
    }
    
    public void recoverTree(TreeNode root) {        
        findTwoSwapped(root);
        swap(x, y);
    }
}