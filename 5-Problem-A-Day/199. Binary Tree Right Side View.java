/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new LinkedList<>();
        if (root == null)
            return ans;
        Queue<TreeNode> nodes = new LinkedList<>();
        Queue<Integer> levels = new LinkedList<>();
        int last = root.val;
        nodes.add(root);
        levels.add(0);
        while (!nodes.isEmpty()) {
            TreeNode node = nodes.remove();
            int level = levels.remove();
            if (level > ans.size())
                ans.add(last);
            if (node.left != null) {
                nodes.add(node.left);
                levels.add(level + 1);
            }
            if (node.right != null) {
                nodes.add(node.right);
                levels.add(level + 1);
            }
            last = node.val;
        }
        ans.add(last);
        return ans;
    }
}
