/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    int count = 0;
    String diff = "";

    public int countUnivalSubtrees(TreeNode root) {
        count(root);
        return count;

    }

    private String count(TreeNode root) {
        if (root == null)
            return "null";
        String left = count(root.left), right = count(root.right);
        if ((left == "null" && right == "null")
                || (left == "null" && right.equals(Integer.toString(root.val)))
                || (right == "null" && left.equals(Integer.toString(root.val)))
                || (left.equals(right) && left.equals(Integer.toString(root.val)))) {
            count += 1;
            return Integer.toString(root.val);
        } else {
            diff += "x";
            return diff;
        }
    }
}
