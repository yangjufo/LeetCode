/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {

    int ans = 0;

    public int longestConsecutive(TreeNode root) {
        if (root == null)
            return 0;
        extend(root.left, root.val, 1);
        extend(root.right, root.val, 1);
        return ans;
    }

    private void extend(TreeNode root, int last, int length) {
        ans = Math.max(length, ans);
        if (root == null)
            return;
        if (root.val == last + 1)
            length += 1;
        else
            length = 1;
        extend(root.left, root.val, length);
        extend(root.right, root.val, length);
    }
}
