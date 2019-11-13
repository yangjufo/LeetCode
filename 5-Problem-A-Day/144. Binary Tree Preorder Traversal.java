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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new LinkedList<>();
        if (root == null) return ans;
        
        Stack<TreeNode> nodes = new Stack<>();
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode node = nodes.pop();
            while(node!= null) {
                ans.add(node.val);
                if (node.right != null) nodes.push(node.right);
                node = node.left;
            }
        }
        return ans;
    }
}
