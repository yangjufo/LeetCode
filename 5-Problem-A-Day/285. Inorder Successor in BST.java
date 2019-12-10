/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if (root == null || p == null)
            return null;
        TreeNode cur;
        if (p.right != null) {
            cur = p.right;
            while (cur.left != null) {
                cur = cur.left;
            }
            return cur;
        }

        Stack<TreeNode> nodes = new Stack<>();
        boolean find = false;
        while (root != null || !nodes.isEmpty()) {
            while (root != null) {
                nodes.push(root);
                root = root.left;
            }
            root = nodes.pop();
            if (root == p)
                find = true;
            else if (find)
                return root;
            root = root.right;
        }
        return null;
    }
}
