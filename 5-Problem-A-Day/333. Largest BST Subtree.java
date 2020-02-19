/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public int largestBSTSubtree(TreeNode root) {
        int[] ans = expand(root);
        return ans[2];
    }

    private int[] expand(TreeNode root) {
        if (root == null)
            return new int[] {Integer.MAX_VALUE, Integer.MIN_VALUE, 0};
        int[] left = expand(root.left);
        int[] right = expand(root.right);
        if (root.val > left[1] && root.val < right[0])
            return new int[] {Math.min(root.val, left[0]), Math.max(root.val, right[1]),
                    left[2] + right[2] + 1};
        else
            return new int[] {Integer.MIN_VALUE, Integer.MAX_VALUE, Math.max(left[2], right[2])};
    }
}
