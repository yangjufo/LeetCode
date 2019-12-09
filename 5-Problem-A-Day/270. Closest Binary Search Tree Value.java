/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public int closestValue(TreeNode root, double target) {
        int ans = root.val;
        while (root != null) {
            if (Math.abs(root.val - target) < Math.abs(ans - target))
                ans = root.val;
            root = root.val < target ? root.right : root.left;
        }
        return ans;
    }

}
