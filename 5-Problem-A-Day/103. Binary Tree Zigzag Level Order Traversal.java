/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        LinkedList<List<Integer>> ans = new LinkedList<>();
        if (root == null)
            return ans;
        Queue<TreeNode> nodes = new LinkedList<>();
        Queue<Integer> levels = new LinkedList<>();
        nodes.add(root);
        levels.add(1);
        int reverse = 1;
        while (nodes.size() > 0) {
            TreeNode node = nodes.remove();
            int level = levels.remove();
            if (level > ans.size()) {
                if (reverse == 1 && ans.size() > 0)
                    Collections.reverse(ans.getLast());
                reverse = 1 - reverse;
                ans.add(new LinkedList<>());
            }
            ans.getLast().add(node.val);
            if (node.left != null) {
                nodes.add(node.left);
                levels.add(level + 1);
            }
            if (node.right != null) {
                nodes.add(node.right);
                levels.add(level + 1);
            }
        }
        if (reverse == 1 && ans.size() > 0)
            Collections.reverse(ans.getLast());
        return ans;
    }
}
