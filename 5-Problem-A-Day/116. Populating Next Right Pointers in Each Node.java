/*
 * // Definition for a Node. class Node { public int val; public Node left; public Node right;
 * public Node next;
 * 
 * public Node() {}
 * 
 * public Node(int _val,Node _left,Node _right,Node _next) { val = _val; left = _left; right =
 * _right; next = _next; } };
 */
class Solution {
    public Node connect(Node root) {
        if (root == null)
            return null;
        Queue<Node> nodes = new LinkedList<>();
        Queue<Integer> levels = new LinkedList<>();
        nodes.add(root);
        levels.add(1);
        Node prev = null;
        int last = 0;
        while (nodes.size() > 0) {
            Node node = nodes.remove();
            int level = levels.remove();
            if (level != last)
                last = level;
            else
                prev.next = node;
            prev = node;
            if (node.left != null) {
                nodes.add(node.left);
                levels.add(level + 1);
            }
            if (node.right != null) {
                nodes.add(node.right);
                levels.add(level + 1);
            }
        }
        return root;
    }
}
