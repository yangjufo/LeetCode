/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public int rob(TreeNode root) {
        int[] ans = up(root);
        return Math.max(ans[0], ans[1]);
    }

    private int[] up(TreeNode root) {
        if (root == null)
            return new int[] {0, 0};
        int[] left = up(root.left);
        int[] right = up(root.right);
        return new int[] {Math.max(root.val + left[1] + right[1], left[0] + right[0]),
                left[0] + right[0]};
    }
}
