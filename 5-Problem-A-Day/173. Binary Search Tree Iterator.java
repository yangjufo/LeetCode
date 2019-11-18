/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {

    Stack<TreeNode> nodes = new Stack<>();
    
    public BSTIterator(TreeNode root) {        
        while (root != null) {
            nodes.push(root);
            root = root.left;
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode node = nodes.pop();
        int ans = node.val;        
        node = node.right;
        while (node != null) {
            nodes.push(node);
            node = node.left;
        }
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !nodes.empty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();