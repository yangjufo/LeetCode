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
    public void flatten(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> nodes = new Stack<>();
        nodes.push(root);
        TreeNode prev = null;
        while (!nodes.empty()) {
            TreeNode node = nodes.pop();
            if (prev == null)
                prev = node;
            else {
                prev.right = node;
                prev = prev.right;
            }
            while (node.left != null) {
                if (node.right != null)
                    nodes.push(node.right);                
                TreeNode tmp = node;
                node = node.left;   
                tmp.left = null;
                prev.right = node;
                prev = prev.right;
            }
            if (node.right != null)
                nodes.push(node.right); 
        }        
    }
}