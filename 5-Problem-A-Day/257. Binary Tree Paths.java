/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new LinkedList<>();
        paths(root, "", ans);
        return ans;
    }

    private void paths(TreeNode root, String curr, List<String> ans) {
        if (root == null)
            return;
        if (root.left == null && root.right == null) {
            curr += Integer.toString(root.val);
            ans.add(curr);
        } else {
            paths(root.left, curr + Integer.toString(root.val) + "->", ans);
            paths(root.right, curr + Integer.toString(root.val) + "->", ans);
        }
    }
}
